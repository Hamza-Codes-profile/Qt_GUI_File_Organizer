# Qt File Organizer

A desktop application built with Qt6/C++ that automatically scans a folder, categorizes files by extension, and organizes them into subfolders — all without freezing the UI, thanks to background threading.

## Features

- **Folder selection** — pick any directory via a native folder picker dialog
- **Live scanning** — recursively scans the selected folder and displays file metadata (name, extension, size, last modified date) in a table view
- **Automatic categorization** — sorts files into subfolders based on extension:
  - Photos (`.png`, `.jpg`)
  - Documents (`.pdf`, `.docx`, `.txt`, `.md`)
  - Videos (`.mp4`)
  - Audio (`.mp3`, `.m4a`)
  - Archives (`.zip`)
  - Executables (`.exe`)
  - Installers (`.msi`)
  - Web Files (`.html`)
  - Python (`.py`)
  - Others (any unmapped extension)
- **Non-blocking UI** — file scanning and moving runs on a separate `QThread`, keeping the interface responsive even on large folders
- **Multi-page dashboard** — sidebar navigation between Home, Organizer, and Settings views using `QStackedWidget`

## Tech Stack

- **Qt 6** (Widgets)
- **C++17**
- Core Qt classes used: `QDir`, `QDirIterator`, `QFileInfo`, `QFile`, `QThread`, `QStandardItemModel`, `QTableView`, `QStackedWidget`, `QListWidget`

## Architecture

- **`MainWindow`** — top-level window managing the sidebar navigation and stacked content views
- **`Navigation`** — sidebar widget emitting a signal when the user switches sections
- **`Organizer`** (view) — UI layer with the folder picker button and results table
- **`organizerWorker`** (`QObject`, not `QWidget`) — background worker class that performs the actual file scanning, categorization, and moving; runs on a dedicated `QThread` via `moveToThread()`, with proper `deleteLater()` cleanup on completion

This separation keeps UI code and business logic decoupled, and ensures file I/O never blocks the main GUI thread.

## How It Works

1. User clicks **Select Folder** and picks a directory
2. An `organizerWorker` is created and moved to a new `QThread`
3. The worker scans every file in the folder, reads its metadata, and determines its target subfolder based on extension
4. Each file's data is emitted back to the UI thread via a signal and appended to the table live, row by row
5. The corresponding subfolder is created (if needed) and the file is moved into it
6. Once scanning completes, the worker emits a `workFinished` signal, which cleanly stops and deletes the thread and worker

## Status

MVP complete — folder selection, live table population, and automatic file organization are all functional.

## Planned Improvements

- Custom user-defined extension → folder rules
- Dry-run / preview mode before committing file moves
- Undo last operation
- Duplicate file detection
- Operation log file
- QSS-based UI styling and polish

## Author

Built by Hamza Arshad as a self-directed learning project, simulating a real freelance client brief (desktop file organization tool) to build practical Qt/C++ skills.
