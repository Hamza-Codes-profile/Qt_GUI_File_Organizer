#ifndef ORGANIZERVIEW_H
#define ORGANIZERVIEW_H

#include "organizerWorker.h"

#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include <QVBoxLayout>
#include <QString>
#include <QWidget>
#include <QThread>

class Organizer: public QWidget{
    Q_OBJECT
public:
    Organizer(QWidget *parent=nullptr);
    ~Organizer();
private:
    QPushButton *selectFolder;
    QLabel *heading;
    QString folderPath;
    QTableView *displayArea;
    QStandardItemModel *displayModel;
    QVBoxLayout *layout;
};

#endif // ORGANIZERVIEW_H
