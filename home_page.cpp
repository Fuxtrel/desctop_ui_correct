#include "home_page.h"

HomePage::HomePage(QWidget *parent, QStackedWidget *stacked_widget):stacked_widget(stacked_widget){
    bg_home_page = new QWidget(parent);
    bg_home_page->setStyleSheet("background-color:#F7F9FB;");

    home_page = new QWidget(bg_home_page);
    home_page->setStyleSheet("background-color:rgba(0,0,0,0);");
    home_page->setGeometry(0, 0, 1380, 944);
    home_page->setFixedSize(1380, 944);

    home_layout = new QGridLayout(bg_home_page);
    home_layout->addWidget(home_page, 0, 0, Qt::AlignLeft);
    home_layout->setContentsMargins(0, 0, 0, 0);
    home_layout->setMargin(0);

    left_buttons_group = new QWidget(home_page);
    left_buttons_group->setGeometry(0, 0, 274, 944);
    left_buttons_group->setStyleSheet("border:0px;background-color:white;border-radius:10px;");

    logo = new QSvgWidget(left_buttons_group);
    logo->setGeometry(30, 30, 197, 45);
    logo->setStyleSheet("border:0px;background-color:rgba(0, 0, 0, 0);");
    logo->load(QString("../pictures/home_page/logo.svg"));

    separator = new QSvgWidget(left_buttons_group);
    separator->setGeometry(30, 105, 214, 1);
    separator->setStyleSheet("border:0px;background-color:rgba(0, 0, 0, 0);");
    separator->load(QString("../pictures/home_page/separator.svg"));

    for(int i = 0; i < 8; i++){
        buttons[i] = new QCommandLinkButton(left_buttons_group);
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

    connect(buttons[0], &QCommandLinkButton::clicked, this, &HomePage::on_command_link_button_0_push);
    connect(buttons[1], &QCommandLinkButton::clicked, this, &HomePage::on_command_link_button_1_push);
    connect(buttons[2], &QCommandLinkButton::clicked, this, &HomePage::on_command_link_button_2_push);
    connect(buttons[3], &QCommandLinkButton::clicked, this, &HomePage::on_command_link_button_3_push);
    connect(buttons[4], &QCommandLinkButton::clicked, this, &HomePage::on_command_link_button_4_push);
    connect(buttons[5], &QCommandLinkButton::clicked, this, &HomePage::on_command_link_button_5_push);
    connect(buttons[6], &QCommandLinkButton::clicked, this, &HomePage::on_command_link_button_6_push);
    connect(buttons[7], &QCommandLinkButton::clicked, this, &HomePage::on_command_link_button_7_push);

    separator_b = new QSvgWidget(left_buttons_group);
    separator_b->setGeometry(30, 538, 214, 1);
    separator_b->setStyleSheet("border:0px;background-color:rgba(0, 0, 0, 0);");
    separator_b->load(QString("../pictures/home_page/separator.svg"));

    last_files = new QLabel(left_buttons_group);
    last_files->setGeometry(40, 563, 170, 23);
    last_files->setText("Последние файлы");
    last_files->setAlignment(Qt::AlignCenter);
    last_files->setStyleSheet("border:0px;background-color:white;font: normal 16px;color:#7D7D7D;");

    stacked_widget_home = new QStackedWidget(home_page);
    stacked_widget_home->setGeometry(334, 0, 1074, 944);

    info_page = new QWidget(home_page);
    info_page->setGeometry(334, 0, 1074, 944);
    info_page->setStyleSheet("background-color:rgba(0, 0, 0, 0);border:0px;");
    stacked_widget_home->addWidget(info_page);

    top_block = new QWidget(info_page);
    top_block->setGeometry(0, 76, 726, 466);
    top_block->setStyleSheet("background-color:white;border:0px;border-radius:10px;");

}

void HomePage::on_command_link_button_0_push() {
    setButtonsDefault();
    if(!buttons_state[0]) {
        buttons[0]->setStyleSheet("border:0px;background-color:#F1F8FE;color:#70BBF6;font: bold 17px;border-radius:7px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_blue_0");
        buttons[0]->setIcon(icon);
        buttons_state[0] = true;
    }else{
        buttons[0]->setStyleSheet("border:0px;background-color:white;color:#9C9C9C;font: normal 17px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_0");
        buttons[0]->setIcon(icon);
        buttons_state[0] = false;
    }
}

void HomePage::on_command_link_button_1_push() {
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

void HomePage::on_command_link_button_2_push() {
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

void HomePage::on_command_link_button_3_push() {
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

void HomePage::on_command_link_button_4_push() {
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

void HomePage::on_command_link_button_5_push() {
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

void HomePage::on_command_link_button_6_push() {
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

void HomePage::on_command_link_button_7_push() {
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

void HomePage::setButtonsDefault() {
    for(int i = 0; i < 8; i++){
        buttons[i]->setStyleSheet("border:0px;background-color:white;color:#9C9C9C;font: normal 17px;");
        QIcon icon;
        icon.addFile("../pictures/home_page/but_" + QString::number(i));
        buttons[i]->setIcon(icon);
        buttons_state[i] = false;
    }
}

