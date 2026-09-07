#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QWidget>

class Navigation: public QWidget{
    Q_OBJECT
public:
    Navigation(QWidget *parent=nullptr);
    ~Navigation();
signals:
    void sendNavIndex(int i);
private:
    QListWidget *navList;
    QListWidgetItem *home;
    QListWidgetItem *organizer;
    QListWidgetItem *settings;
};

#endif // NAVIGATION_H
