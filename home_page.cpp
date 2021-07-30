#include "home_page.h"

HomePage::HomePage(QWidget *parent){
    bg_home_page = new QWidget(parent);
    bg_home_page->setStyleSheet("background-color:#F7F9FB;");
    home_page = new QWidget(bg_home_page);
    home_page->setStyleSheet("background-color:rgba(0,0,0,0);");
    home_page->setGeometry(300, 300, 300, 300);
    home_page->setFixedSize(1440, 1024);
    home_layout = new QGridLayout(bg_home_page);
    home_layout->addWidget(home_page, 1, 1, Qt::AlignCenter);
}

QWidget *HomePage::getLinkBgHomePage() {
    return bg_home_page;
}