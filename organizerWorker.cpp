#include "organizerWorker.h"

organizerWorker::organizerWorker(QObject *parent, QString directory): QObject(parent)
{
    extensionMap["exe"] = "Executables";
    extensionMap["png"] = "Photos";
    extensionMap["jpg"] = "Photos";
    extensionMap["pdf"] = "Documents";
    extensionMap["mp4"] = "Videos";
    extensionMap["zip"] = "Archives";
    extensionMap["html"] = "Web Files";
    extensionMap["msi"] = "Installers";
    extensionMap["mp3"] = "Audio";
    extensionMap["m4a"] = "Audio";
    extensionMap["docx"] = "Documents";
    extensionMap["txt"] = "Documents";
    extensionMap["md"] = "Documents";
    extensionMap["py"] = "Python";

    messyFolder = QDir(directory);
}

void organizerWorker::processData(){
    qDebug()<<QThread::currentThread();
    if(messyFolder.exists()){
        qDebug()<<"Folder: "<<messyFolder.path();
        QDirIterator it(messyFolder.path(), QDir::Files | QDir::NoDotAndDotDot);
        while(it.hasNext()){
            rowData.clear();
            filePath = it.next();
            QFileInfo fileMeta(filePath);
            QString name = fileMeta.fileName();
            QString ext = fileMeta.suffix();
            QString size = QString::number(fileMeta.size());
            QString dateModf = fileMeta.lastModified().toString();
            rowData.append(name);
            rowData.append(ext);
            rowData.append(size);
            rowData.append(dateModf);
            if(extensionMap.contains(ext)){
                targetFolder = extensionMap.value(ext);
            }
            else{
                targetFolder = "Others";
            }
            messyFolder.mkdir(targetFolder);
            QFile currentFile(filePath);
            currentFile.rename(messyFolder.path()+"//"+targetFolder+ "//"+name);
            rowData.append(targetFolder);
            emit sendFileRowData(rowData);
        }
    }
    else{
        qDebug()<<"No such directory exists.";
    }
    emit workFinished(true);
}