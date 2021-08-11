#include "file_page.h"

FilePage::FilePage(QWidget *parent, QStackedWidget *stacked_widget):stacked_widget(stacked_widget) {

    bg_file_page = new QWidget(parent);
    bg_file_page->setGeometry(0, 0, 1920, 1080);
    bg_file_page->setStyleSheet("background-color:#F7F9FB;border:0px;");

    left_buttons_block = new QWidget(bg_file_page);
    left_buttons_block->setGeometry(0, 0, 274, 944);
    left_buttons_block->setStyleSheet("background-color:white;border:0px;border-radius:10px;");
    left_buttons_block->setMaximumWidth(274);
    left_buttons_block->setMinimumHeight(944);

    layout = new QGridLayout(bg_file_page);
    layout->setSpacing(15);

    stacked_widget_file_out = new QStackedWidget(bg_file_page);
    stacked_widget_file_out->setGeometry(30, 0, 726, 868);
    stacked_widget_file_out->setStyleSheet("background-color:rgba(0, 0, 0, 0);border:0px;");
    stacked_widget_file_out->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    top_block = new QWidget(bg_file_page);
    top_block->setGeometry(0, 0, 1066, 234);
    top_block->setStyleSheet("background-color:white;border:0px;border-radius:10px;");



    layout->addWidget(left_buttons_block, 0, 0, 2, 1);
    layout->addWidget(stacked_widget_file_out, 1, 1, 1, 1);
    layout->addWidget(top_block, 0, 1, 1, 1);

    scroll_area_file = new QScrollArea(bg_file_page);
    scroll_area_file->setGeometry(30, 0, 726, 868);
    scroll_area_file->setStyleSheet("background-color:white;border:0px;border-radius:10px;");
    stacked_widget_file_out->addWidget(scroll_area_file);

    layout->setColumnMinimumWidth(0, 274);
    layout->setColumnMinimumWidth(1, 726);
    layout->setRowMinimumHeight(1, 604);
    layout->setRowMinimumHeight(0, 234);

    stacked_widget_file_layout = new QGridLayout(scroll_area_file);
    stacked_widget_file_layout->setMargin(30);


}
