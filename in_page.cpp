#include "in_page.h"

InPage::InPage(QWidget *parent) {
    {
        bg_in_page = new QWidget(parent);
        bg_in_page->setStyleSheet("background-color:white;");
    }
    {
        in_page = new QWidget(bg_in_page);
        in_page->setStyleSheet("background-color:blue;");
        in_page->setGeometry(300, 3000, 300, 300);
        in_page->setFixedSize(1280, 780);
    }
    in_layout = new QGridLayout(bg_in_page);
    in_layout->addWidget(in_page, 1, 1, Qt::AlignCenter);
    in_page->show();
}

QWidget *InPage::getLinkBgInPage() {
    return bg_in_page;
}
