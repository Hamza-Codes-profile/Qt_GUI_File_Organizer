#ifndef ORGANIZERWORKER_H
#define ORGANIZERWORKER_H

#include <QWidget>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QString>
#include <QList>
#include <QFileInfo>
#include <QMap>
#include <QDateTime>
#include <QFile>
#include <QObject>
#include <QThread>

class organizerWorker : public QObject
{
    Q_OBJECT
public:
    explicit organizerWorker(QObject *parent = nullptr, QString directory="D:\\Python\\python");
    void processData();

signals:
    void sendFileRowData(QList<QString> rowData);
    void workFinished(bool status);

private:
    QDir messyFolder;
    QList<QString> rowData;
    QString filePath;
    QString targetFolder;
    QMap<QString, QString> extensionMap;
};

#endif // ORGANIZERWORKER_H
