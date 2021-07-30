#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    in_page = new InPage(this);
    reg_page = new RegPage(this);
    home_page = new HomePage(this);


    stacked_widget = new QStackedWidget(this);
    stacked_widget->setGeometry(0, 0, 1000, 1000);
    stacked_widget->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    stacked_widget->addWidget(reg_page->getLinkBgRegPage());
    stacked_widget->addWidget(in_page->getLinkBgInPage());
    stacked_widget->addWidget(home_page->getLinkBgHomePage());

    auto *bodyShadow = new CustomShadowEffect();
    bodyShadow->setBlurRadius(20.0);
    bodyShadow->setDistance(3.0);
    bodyShadow->setColor(QColor(0, 0, 0, 80));

    int count_effects = 2;
    CustomShadowEffect *shadow[count_effects];
    for (int i = 0; i < count_effects; i++) {
        shadow[i] = new CustomShadowEffect();
        shadow[i]->setBlurRadius(20.0);
        shadow[i]->setDistance(3.0);
        shadow[i]->setColor(QColor(0, 0, 0, 20));
    }

    in_page->getLinkBgEmailInputInPage()->setGraphicsEffect(shadow[0]);
    in_page->getLinkBgPasswordInputInPage()->setGraphicsEffect(shadow[1]);


    stacked_widget->setCurrentIndex(1);
//    timer = new QTimer();
//    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
//    timer->start(1000);
}

void MainWindow::on_but_clicked() {
    stacked_widget->setCurrentIndex(1);
    timer->start(1000);
}

void MainWindow::onTimeout() {
    i++;
    stacked_widget->setCurrentIndex(i);
    if(i == 2){
        timer->stop();
    }
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    QPoint null_point(0, 0);
    stacked_widget->resize(event->size().width(), event->size().height());
}
