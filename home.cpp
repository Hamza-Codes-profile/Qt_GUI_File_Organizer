#include "home.h"

HomeStack::HomeStack(QWidget *parent){
    homeLayout = new QVBoxLayout(this);
    homeLayout->setAlignment(Qt::AlignTop);

    // home welcome text
    homeHeading = new QLabel("Welcome to the Dashboard!", this);
    homeHeading->setStyleSheet("font-size:30px;"
                               "font-family:Poppins;"
                               "font-weight:bold");
    homeHeading->setAlignment(Qt::AlignCenter);
    homeLayout->addWidget(homeHeading);

    // home overview
    overview = new QLabel("This is a simple dashboard", this);
    overview->setStyleSheet("font-size:15px;"
                               "font-family:Poppins;");
    overview->setAlignment(Qt::AlignCenter);
    homeLayout->addWidget(overview);
    setLayout(homeLayout);
}

HomeStack::~HomeStack(){

}