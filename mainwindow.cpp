#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setMinimumSize(800,500);

    // central Container
    QWidget *centralContainer = new QWidget(this);
    setCentralWidget(centralContainer);

    // Master Layout
    masterLayout = new QVBoxLayout(centralContainer);

    // Top Heading
    heading = new QLabel("Dashboard", this);
    heading->setMaximumHeight(100);
    heading->setAlignment(Qt::AlignCenter);
    heading->setStyleSheet("font-size: 40px; font-weight: bold;");
    masterLayout->addWidget(heading);

    // Main Layout
    wrapper = new QHBoxLayout();
    masterLayout->addLayout(wrapper);

    // Navigation
    navPanel = new QVBoxLayout();
    wrapper->addLayout(navPanel);

    // Main View Stack
    mainViewStack = new QStackedWidget(this);
    mainViewStack->setCurrentIndex(0);
    wrapper->addWidget(mainViewStack);

    // Home Stack/View
    homeView = new HomeStack(this);
    mainViewStack->addWidget(homeView);

    // // Organizer
    organizerView = new Organizer(this);
    mainViewStack->addWidget(organizerView);

    // Navigation
    nav = new Navigation(this);
    nav->setMinimumWidth(200);
    navPanel->addWidget(nav);

    connect(nav, &Navigation::sendNavIndex, this, &MainWindow::handleMultiView);
}

void MainWindow::handleMultiView(int i){
    mainViewStack->setCurrentIndex(i);
}

MainWindow::~MainWindow()
{
    delete ui;
}
