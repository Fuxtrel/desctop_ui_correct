#include "file_page.h"

FilePage::FilePage(QWidget *parent, QStackedWidget *stacked_widget):stacked_widget(stacked_widget) {

    bg_file_page = new QWidget(parent);
    bg_file_page->setGeometry(0, 0, 1920, 1080);
    bg_file_page->setStyleSheet("background-color:#F7F9FB;border:0px;");

    left_buttons_block = new QWidget(bg_file_page);
    left_buttons_block->setGeometry(0, 0, 274, 944);
    left_buttons_block->setStyleSheet("background-color:green;border:0px;border-radius:10px;");
    left_buttons_block->setMaximumWidth(274);

    layout = new QGridLayout(bg_file_page);

    stacked_widget_file_out = new QStackedWidget(bg_file_page);
    stacked_widget_file_out->setGeometry(30, 0, 726, 868);
    stacked_widget_file_out->setStyleSheet("background-color:rgba(0, 0, 0, 0);border:0px;");
    stacked_widget_file_out->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    layout->addWidget(left_buttons_block, 1, 0, Qt::AlignLeft, Qt::AlignTop);
    layout->addWidget(stacked_widget_file_out, 1, 1, Qt::AlignLeft, Qt::AlignTop);
    scroll_area_file = new QScrollArea(bg_file_page);
    scroll_area_file->setGeometry(30, 0, 726, 868);
    scroll_area_file->setStyleSheet("background-color:red;border:0px;border-radius:10px;");
    stacked_widget_file_out->addWidget(scroll_area_file);

    layout->setColumnMinimumWidth(0, 274);
    layout->setColumnMinimumWidth(1, 726);

    stacked_widget_file_layout = new QGridLayout(scroll_area_file);
}
