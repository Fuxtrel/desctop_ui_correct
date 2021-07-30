#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    in_page = new InPage(this);

    {
        stacked_widget = new QStackedWidget(this);
        stacked_widget->setGeometry(0, 0, 1000, 1000);
        stacked_widget->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    }
    {
        bg_reg_page = new QWidget(this);
        bg_reg_page->setStyleSheet("background-color:white;");

    }
//    {
//        bg_in_page = new QWidget(this);
//        bg_in_page->setStyleSheet("background-color:white;");
//
//    }
    {
        bg_home_page = new QWidget(this);
        bg_home_page->setStyleSheet("background-color:white;");

    }
    {
        reg_page = new QWidget(bg_reg_page);
        reg_page->setStyleSheet("background-color:green");
        reg_page->setGeometry(300, 300, 300, 300);
        reg_page->setFixedSize(1280, 780);
    }
//    {
//        in_page = new QWidget(bg_in_page);
//        in_page->setStyleSheet("background-color:blue;");
//        in_page->setGeometry(300, 3000, 300, 300);
//        in_page->setFixedSize(1280, 780);
//    }
    {
        home_page = new QWidget(bg_home_page);
        home_page->setStyleSheet("background-color:yellow;");
        home_page->setGeometry(300, 3000, 300, 300);
        home_page->setFixedSize(1280, 780);
    }
    {
        reg_layout = new QGridLayout(bg_reg_page);
        reg_layout->addWidget(reg_page, 1, 1, Qt::AlignCenter);
        reg_page->show();

//        in_layout = new QGridLayout(bg_in_page);
//        in_layout->addWidget(in_page, 1, 1, Qt::AlignCenter);
//        in_page->show();

        home_layout = new QGridLayout(bg_home_page);
        home_layout->addWidget(home_page, 1, 1, Qt::AlignCenter);
        home_page->show();

        stacked_widget->addWidget(bg_reg_page);
        stacked_widget->addWidget(in_page->getLinkBgInPage());
        stacked_widget->addWidget(bg_home_page);
    }


    stacked_widget->setCurrentIndex(1);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

void MainWindow::on_but_clicked() {
    stacked_widget->setCurrentIndex(1);
    timer->start(1000);
}

void MainWindow::onTimeout() {

    stacked_widget->setCurrentIndex(0);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    QPoint null_point(0, 0);
    stacked_widget->resize(event->size().width(), event->size().height());
}
