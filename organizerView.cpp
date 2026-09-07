#include "organizerView.h"

Organizer::Organizer(QWidget *parent){
    displayModel = new QStandardItemModel(this);
    displayModel->setHorizontalHeaderLabels({"File Name", "Extension", "Size", "Last Modified", "Target Folder"});
    displayArea = new QTableView(this);
    selectFolder = new QPushButton("Select Folder", this);
    layout = new QVBoxLayout(this);
    layout->addWidget(selectFolder);
    layout->addWidget(displayArea);

    connect(selectFolder, &QPushButton::clicked, this, [this](){
        folderPath = QFileDialog::
            getExistingDirectory(nullptr, "Select Folder", "D:\\Python\\python",
                                 QFileDialog::ShowDirsOnly);
        organizerWorker *organizer = new organizerWorker(nullptr, folderPath);
        connect(organizer, &organizerWorker::sendFileRowData, this, [this](QList<QString> fileData){
            QList<QStandardItem*> tableRow;
            tableRow.append(new QStandardItem(fileData[0]));
            tableRow.append(new QStandardItem(fileData[1]));
            tableRow.append(new QStandardItem(fileData[2]));
            tableRow.append(new QStandardItem(fileData[3]));
            tableRow.append(new QStandardItem(fileData[4]));
            displayModel->appendRow(tableRow);
        });
        qDebug()<<QThread::currentThread();
        QThread *processThread = new QThread();
        organizer->moveToThread(processThread);
        connect(processThread, &QThread::started, organizer, &organizerWorker::processData);
        connect(organizer, &organizerWorker::workFinished, processThread, &QThread::quit);
        connect(processThread, &QThread::finished, organizer, &QObject::deleteLater);
        connect(processThread, &QThread::finished, processThread, &QThread::deleteLater);
        processThread->start();
    });
    setLayout(layout);
    displayArea->setModel(displayModel);
}

Organizer::~Organizer(){

}