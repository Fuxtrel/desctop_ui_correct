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

    find_place = new QWidget(bg_file_page);
    find_place->setGeometry(0, 0, 1066, 46);
    find_place->setMinimumSize(726, 46);

    layout->addWidget(left_buttons_block, 0, 0, 3, 1);
    layout->addWidget(find_place, 0, 1, 1, 1);
    layout->addWidget(top_block, 1, 1, 1, 1);
    layout->addWidget(stacked_widget_file_out, 2, 1, 1, 1);

    scroll_area_file = new QScrollArea(bg_file_page);
    scroll_area_file->setGeometry(30, 0, 726, 868);
    scroll_area_file->setStyleSheet("background-color:white;border:0px;border-radius:10px;");
    stacked_widget_file_out->addWidget(scroll_area_file);

    layout->setColumnMinimumWidth(0, 274);
    layout->setColumnMinimumWidth(1, 726);
    layout->setRowMinimumHeight(1, 604);
    layout->setRowMinimumHeight(0, 234);
    layout->setRowMinimumHeight(0, 46);

    stacked_widget_file_layout = new QGridLayout(scroll_area_file);
    stacked_widget_file_layout->setMargin(30);

    for(int i = 0; i < 8; i++){
        buttons[i] = new QCommandLinkButton(left_buttons_block);
        buttons[i]->setGeometry(30, 130 + (50 * i), 214, 44);
        buttons[i]->setStyleSheet("QCommandLinkButton{border:0px;background-color:white;color:#9C9C9C;font: normal 17px;}"
                                  "QCommandLinkButton:pressed{border:0px;background-color:#F1F8FE;color:#70BBF6;font: bold 17px;border-radius:7px;}");
        QIcon icon;
        icon.addFile(QString("../pictures/home_page/but_" + QString::number(i)));
        buttons[i]->setIcon(icon);
        buttons[i]->setIconSize(QSize(22, 22));
        buttons[i]->setFocusPolicy(Qt::NoFocus);
    }
    buttons[0]->setText("Главная");
    buttons[1]->setText("Файлы");
    buttons[2]->setText("Медиа");
    buttons[3]->setText("Избранное");
    buttons[4]->setText("Сдача места");
    buttons[5]->setText("Финансы");
    buttons[6]->setText("Настройки");
    buttons[7]->setText("Корзина");

    connect(buttons[0], &QCommandLinkButton::clicked, this, &FilePage::on_command_link_button_0_push);
    connect(buttons[1], &QCommandLinkButton::clicked, this, &FilePage::on_command_link_button_1_push);
    connect(buttons[2], &QCommandLinkButton::clicked, this, &FilePage::on_command_link_button_2_push);
    connect(buttons[3], &QCommandLinkButton::clicked, this, &FilePage::on_command_link_button_3_push);
    connect(buttons[4], &QCommandLinkButton::clicked, this, &FilePage::on_command_link_button_4_push);
    connect(buttons[5], &QCommandLinkButton::clicked, this, &FilePage::on_command_link_button_5_push);
    connect(buttons[6], &QCommandLinkButton::clicked, this, &FilePage::on_command_link_button_6_push);
    connect(buttons[7], &QCommandLinkButton::clicked, this, &FilePage::on_command_link_button_7_push);

    logo = new QSvgWidget(left_buttons_block);
    logo->setGeometry(30, 30, 197, 45);
    logo->setStyleSheet("border:0px;background-color:rgba(0, 0, 0, 0);");
    logo->load(QString("../pictures/home_page/logo.svg"));

}

void FilePage::setButtonsDefault() {
    for(int i = 0; i < 8; i++){
        buttons[i]->setStyleSheet("border:0px;background-color:white;color:#9C9C9C;font: normal 17px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_" + QString::number(i));
        buttons[i]->setIcon(icon);
        buttons_state[i] = false;
    }
}


void FilePage::on_command_link_button_0_push() {
    setButtonsDefault();
//    if(!buttons_state[0]) {
//        buttons[0]->setStyleSheet("border:0px;background-color:#F1F8FE;color:#70BBF6;font: bold 17px;border-radius:7px;");
//        QIcon icon;
//        icon.addFile("../pictures/home_page/but_blue_0");
//        buttons[0]->setIcon(icon);
//        buttons_state[0] = true;
//    }else{
//        buttons[0]->setStyleSheet("border:0px;background-color:white;color:#9C9C9C;font: normal 17px;");
//        QIcon icon;
//        icon.addFile("../pictures/home_page/but_0");
//        buttons[0]->setIcon(icon);
//        buttons_state[0] = false;
//    }
    stacked_widget->setCurrentIndex(2);
}

void FilePage::on_command_link_button_1_push() {
    setButtonsDefault();
    if(!buttons_state[1]) {
        buttons[1]->setStyleSheet("border:0px;background-color:#F1F8FE;color:#70BBF6;font: bold 17px;border-radius:7px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_blue_1");
        buttons[1]->setIcon(icon);
        buttons_state[1] = true;
    }else{
        buttons[1]->setStyleSheet("border:0px;background-color:white;color:#9C9C9C;font: normal 17px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_1");
        buttons[1]->setIcon(icon);
        buttons_state[1] = false;
    }

}

void FilePage::on_command_link_button_2_push() {
    setButtonsDefault();
    if(!buttons_state[2]) {
        buttons[2]->setStyleSheet("border:0px;background-color:#F1F8FE;color:#70BBF6;font: bold 17px;border-radius:7px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_blue_2");
        buttons[2]->setIcon(icon);
        buttons_state[2] = true;
    }else{
        buttons[2]->setStyleSheet("border:0px;background-color:white;color:#9C9C9C;font: normal 17px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_2");
        buttons[2]->setIcon(icon);
        buttons_state[2] = false;
    }
}

void FilePage::on_command_link_button_3_push() {
    setButtonsDefault();
    if(!buttons_state[3]) {
        buttons[3]->setStyleSheet("border:0px;background-color:#F1F8FE;color:#70BBF6;font: bold 17px;border-radius:7px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_blue_3");
        buttons[3]->setIcon(icon);
        buttons_state[3] = true;
    }else{
        buttons[3]->setStyleSheet("border:0px;background-color:white;color:#9C9C9C;font: normal 17px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_3");
        buttons[3]->setIcon(icon);
        buttons_state[3] = false;
    }
}

void FilePage::on_command_link_button_4_push() {
    setButtonsDefault();
    if(!buttons_state[4]) {
        buttons[4]->setStyleSheet("border:0px;background-color:#F1F8FE;color:#70BBF6;font: bold 17px;border-radius:7px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_blue_4");
        buttons[4]->setIcon(icon);
        buttons_state[4] = true;
    }else{
        buttons[4]->setStyleSheet("border:0px;background-color:white;color:#9C9C9C;font: normal 17px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_4");
        buttons[4]->setIcon(icon);
        buttons_state[4] = false;
    }
}

void FilePage::on_command_link_button_5_push() {
    setButtonsDefault();
    if(!buttons_state[5]) {
        buttons[5]->setStyleSheet("border:0px;background-color:#F1F8FE;color:#70BBF6;font: bold 17px;border-radius:7px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_blue_5");
        buttons[5]->setIcon(icon);
        buttons_state[5] = true;
    }else{
        buttons[5]->setStyleSheet("border:0px;background-color:white;color:#9C9C9C;font: normal 17px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_5");
        buttons[5]->setIcon(icon);
        buttons_state[5] = false;
    }
}

void FilePage::on_command_link_button_6_push() {
    setButtonsDefault();
    if(!buttons_state[6]) {
        buttons[6]->setStyleSheet("border:0px;background-color:#F1F8FE;color:#70BBF6;font: bold 17px;border-radius:7px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_blue_6");
        buttons[6]->setIcon(icon);
        buttons_state[6] = true;
    }else{
        buttons[6]->setStyleSheet("border:0px;background-color:white;color:#9C9C9C;font: normal 17px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_6");
        buttons[6]->setIcon(icon);
        buttons_state[6] = false;
    }
}

void FilePage::on_command_link_button_7_push() {
    setButtonsDefault();
    if(!buttons_state[7]) {
        buttons[7]->setStyleSheet("border:0px;background-color:#F1F8FE;color:#70BBF6;font: bold 17px;border-radius:7px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_blue_7");
        buttons[7]->setIcon(icon);
        buttons_state[7] = true;
    }else{
        buttons[7]->setStyleSheet("border:0px;background-color:white;color:#9C9C9C;font: normal 17px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_7");
        buttons[7]->setIcon(icon);
        buttons_state[7] = false;
    }
}