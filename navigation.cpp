#include "navigation.h"

Navigation::Navigation(QWidget *parent){
    this->setStyleSheet("font-family: Roboto; font-weight: bold; font-size: 18px;");
    navList = new QListWidget(this);
    navList->setMinimumHeight(500);
    home = new QListWidgetItem(tr("Home"),navList);
    organizer = new QListWidgetItem(tr("Organizer"),navList);
    settings = new QListWidgetItem(tr("Settings"),navList);
    navList->setCurrentRow(0);
    connect(navList, &QListWidget::currentRowChanged, this, [this](int i){
        emit sendNavIndex(i);
    });
}
Navigation::~Navigation(){

}