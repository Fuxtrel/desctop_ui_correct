#include "reg_page.h"

RegPage::RegPage(QWidget *parent) {

    bg_reg_page = new QWidget(parent);
    bg_reg_page->setStyleSheet("background-color:#F7F9FB;");
    reg_page = new QWidget(bg_reg_page);
    reg_page->setStyleSheet("background-color:rgba(0,0,0,0)");
    reg_page->setGeometry(300, 300, 300, 300);
    reg_page->setFixedSize(1280, 780);
    reg_layout = new QGridLayout(bg_reg_page);
    reg_layout->addWidget(reg_page, 1, 1, Qt::AlignCenter);
}

QWidget *RegPage::getLinkBgRegPage() {
    return bg_reg_page;
}