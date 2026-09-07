#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "home.h"
#include "navigation.h"
#include "organizerView.h"

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
public slots:
    void handleMultiView(int i);
private:
    Ui::MainWindow *ui;
    QVBoxLayout *masterLayout;
    QHBoxLayout *wrapper;
    QVBoxLayout *navPanel;
    QLabel *heading;
    Navigation *nav;
    QStackedWidget *mainViewStack;
    HomeStack *homeView;
    Organizer *organizerView;
};
#endif // MAINWINDOW_H
