#include <search.h>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    stacked_widget = new QStackedWidget(this);
    stacked_widget->setGeometry(0, 0, 1000, 1000);
    stacked_widget->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    home_page = new HomePage(this, stacked_widget);
    rg = new fux::RoundGraph(143, 89, 160, 10, QBrush(QColor::fromRgb(134, 143, 255)), QBrush(Qt::white), home_page->top_block);
    rg_ = new fux::RoundGraph(343, 89, 160, 10, QBrush(QColor::fromRgb(89, 215, 171)), QBrush(Qt::white), home_page->top_block);
    in_page = new InPage(this, stacked_widget, rg, rg_);
    reg_page = new RegPage(this, stacked_widget);

    stacked_widget->addWidget(reg_page->getLinkBgRegPage());
    stacked_widget->addWidget(in_page->bg_in_page);
    stacked_widget->addWidget(home_page->bg_home_page);

    auto *bodyShadow = new CustomShadowEffect();
    bodyShadow->setBlurRadius(20.0);
    bodyShadow->setDistance(3.0);
    bodyShadow->setColor(QColor(0, 0, 0, 80));

    int count_effects = 13;
    CustomShadowEffect *shadow[count_effects];
    for (int i = 0; i < count_effects; i++) {
        shadow[i] = new CustomShadowEffect();
        shadow[i]->setBlurRadius(20.0);
        shadow[i]->setDistance(3.0);
        shadow[i]->setColor(QColor(0, 0, 0, 40));
    }

    in_page->bg_email_input->setGraphicsEffect(shadow[0]);
    in_page->bg_password_input->setGraphicsEffect(shadow[1]);
    in_page->check_box_in_page->setGraphicsEffect(shadow[2]);
    in_page->facebook->setGraphicsEffect(shadow[3]);
    in_page->google->setGraphicsEffect(shadow[4]);
    in_page->sign_in->setGraphicsEffect(shadow[5]);
    in_page->in_page->setGraphicsEffect(shadow[6]);
    reg_page->reg_page->setGraphicsEffect(shadow[7]);
    reg_page->bg_fio_input->setGraphicsEffect(shadow[8]);
    reg_page->bg_email_input->setGraphicsEffect(shadow[9]);
    reg_page->bg_password_input->setGraphicsEffect(shadow[10]);
    reg_page->check_box_reg_page->setGraphicsEffect(shadow[11]);
    reg_page->registration->setGraphicsEffect(shadow[12]);

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
    if (i == 2) {
        timer->stop();
    }
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    stacked_widget->resize(event->size().width(), event->size().height());
    switch(stacked_widget->currentIndex()){
        case 2:
            setMinimumSize(1380, 944);
            break;
        default:
            setMinimumSize(1280, 780);
            break;
    }
}
