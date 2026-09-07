#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class HomeStack : public QWidget
{
    Q_OBJECT
public:
    explicit HomeStack(QWidget *parent = nullptr);
    ~HomeStack();

private:
    QVBoxLayout *homeLayout;
    QLabel *homeHeading;
    QLabel *overview;
};

#endif // HOME_H