#include "home_page.h"

HomePage::HomePage(QWidget *parent, QStackedWidget *stacked_widget):stacked_widget(stacked_widget){
    bg_home_page = new QWidget(parent);
    bg_home_page->setStyleSheet("background-color:#F7F9FB;");

    home_page = new QWidget(bg_home_page);
    home_page->setStyleSheet("background-color:rgba(0,0,0,0);");
    home_page->setGeometry(0, 0, 1380, 944);
    home_page->setFixedSize(1380, 944);

    home_layout = new QGridLayout(bg_home_page);
    home_layout->addWidget(home_page, 1, 1, Qt::AlignCenter);
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
    connect(buttons[1], &QCommandLinkButton::clicked, this, &HomePage::on_file_page_clicked);
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

    info_page = new QWidget(home_page);
    info_page->setGeometry(304, 0, 1074, 944);
    info_page->setStyleSheet("background-color:rgba(0, 0, 0, 0);border:0px;");

    template_bg = new QWidget(home_page);
    template_bg->setGeometry(274, 0, 1126, 944);
    template_bg->setStyleSheet("background-color:rgba(0, 0, 0, 0);");


    top_block = new QWidget(info_page);
    top_block->setGeometry(0, 76, 726, 466);
    top_block->setStyleSheet("background-color:white;border:0px;border-radius:10px;");

    place_on_your = new QLabel(top_block);
    place_on_your->setGeometry(66, 234, 276, 17);
    place_on_your->setText("Места на вашем устройстве арендовано");
    place_on_your->setStyleSheet("border:0px;background-color:white;font: normal 15px;color:#5F5F5F;");

    place_on_your = new QLabel(top_block);
    place_on_your->setGeometry(414, 234, 229, 17);
    place_on_your->setText("Арендованого места заполнено");
    place_on_your->setStyleSheet("border:0px;background-color:white;font: normal 15px;color:#5F5F5F;");

    for(int i = 0; i < 2; i++){
        separators[i] = new QSvgWidget(top_block);
        separators[i]->setGeometry(103 + i * 321, 271, 200, 1);
        separators[i]->setStyleSheet("border:0px;background-color:white;");
        separators[i]->load(QString("../pictures/home_page/separator.svg"));
    }

    for(int i = 0; i < 2; i++){
        money[i] = new QLabel(top_block);
        money[i]->setGeometry(50 + i * 335, 291, 300, 50);
        money[i]->setStyleSheet("border:0px;background-color:white;font: normal 40px;color:#70BBF6;");
        money[i]->setAlignment(Qt::AlignCenter);
    }
    money[0]->setText("50 ₽");
    money[1]->setText("3000 ₽");

    increase = new QPushButton(top_block);
    increase->setGeometry(104, 394, 200, 46);
    increase->setText("Увеличить");
    increase->setStyleSheet("background-color:#F7F9FB;color:#7D7D7D;border:0px;border-radius:10px;");

    out = new QPushButton(top_block);
    out->setGeometry(424, 394, 200, 46);
    out->setText("Вывести");
    out->setStyleSheet("background-color:#F7F9FB;color:#7D7D7D;border:0px;border-radius:10px;");

    you_rent_out = new QLabel(top_block);
    you_rent_out->setGeometry(40, 20, 96, 24);
    you_rent_out->setText("Вы сдаёте");
    you_rent_out->setAlignment(Qt::AlignCenter);
    you_rent_out->setStyleSheet("border:0px;background-color:white;color:#5F5F5F;font: normal 20px;");

    top_separator = new QSvgWidget(top_block);
    top_separator->setGeometry(40, 64, 646, 1);
    top_separator->setStyleSheet("border:0px;background-color:white;");
    top_separator->load(QString("../pictures/home_page/separator.svg"));

    bottom_block = new QWidget(info_page);
    bottom_block->setGeometry(0, 572, 726, 372);
    bottom_block->setStyleSheet("border:0px;border-radius:10px;background-color:white;");

    you_rent = new QLabel(bottom_block);
    you_rent->setGeometry(40, 20, 131, 24);
    you_rent->setText("Вы арендуете");
    you_rent->setAlignment(Qt::AlignCenter);
    you_rent->setStyleSheet("border:0px;background-color:white;color:#5F5F5F;font: normal 20px;");

    bottom_separator = new QSvgWidget(bottom_block);
    bottom_separator->setGeometry(40, 64, 646, 1);
    bottom_separator->setStyleSheet("border:0px;background-color:white;");
    bottom_separator->load(QString("../pictures/home_page/separator.svg"));

    space_is_full = new QLabel(bottom_block);
    space_is_full->setGeometry(40, 82, 222, 29);
    space_is_full->setText("Пространство заполнено на: ");
    space_is_full->setAlignment(Qt::AlignCenter);
    space_is_full->setStyleSheet("background-color:white;border:0px;color:#9C9C9C;font: normal 16px;");

    space_load = new QLabel(bottom_block);
    space_load->setGeometry(262, 79, 70, 40);
    space_load->setText("70 %");
    space_load->setAlignment(Qt::AlignLeft);
    space_load->setStyleSheet("background-color:white;color:#7D7D7D;font: normal 24px;border:0px;");

    bottom_progress_bar = new QProgressBar(bottom_block);
    bottom_progress_bar->setGeometry(40, 136, 646, 8);
    bottom_progress_bar->setStyleSheet("QProgressBar {"
                                       "border:0px;"
                                       "background-color:#F7F9FB;"
                                       "border-radius: 4px;"
                                       "}"
                                       "QProgressBar::chunk{"
                                       "background-color: #868FFF;"
                                       "border:0px;"
                                       "border-radius: 4px;"
                                       "}");
    bottom_progress_bar->setValue(70);
    bottom_progress_bar->setTextVisible(false);

    for(int i = 0; i < 3; i++){
        sign_progress_bar[i] = new QLabel(bottom_block);
        sign_progress_bar[i]->setGeometry(30 + i * (40 + 270), 154, 40, 14);
        sign_progress_bar[i]->setAlignment(Qt::AlignCenter);
        sign_progress_bar[i]->setText(QString::number(i * 50) + " %");
        sign_progress_bar[i]->setStyleSheet("border:0px;background-color:white;color:#9C9C9C;");
    }

    every_day_pay = new QLabel(top_block);
    every_day_pay->setGeometry(120, 345, 160, 17);
    every_day_pay->setText("Ежедневный доход");
    every_day_pay->setAlignment(Qt::AlignCenter);
    every_day_pay->setStyleSheet("background-color:white;border:0px;color:#5F5F5F;font: normal 16px;");

    your_balance = new QLabel(top_block);
    your_balance->setGeometry(483, 345, 100, 17);
    your_balance->setText("Ваш баланс");
    your_balance->setAlignment(Qt::AlignCenter);
    your_balance->setStyleSheet("background-color:white;border:0px;color:#5F5F5F;font: normal 16px;");

    using_space = new QLabel(bottom_block);
    using_space->setGeometry(132, 252, 143, 17);
    using_space->setText("Используемое место");
    using_space->setStyleSheet("border:0px;background-color:white;font: normal 14px;color:#5F5F5F;");
    using_space->setAlignment(Qt::AlignCenter);

    next_pay = new QLabel(bottom_block);
    next_pay->setGeometry(465, 252, 135, 17);
    next_pay->setText("Следующий платёж");
    next_pay->setStyleSheet("border:0px;background-color:white;font: normal 14px;color:#5F5F5F;");
    next_pay->setAlignment(Qt::AlignCenter);

    using_space_count = new QLabel(bottom_block);
    using_space_count->setGeometry(135, 198, 140, 43);
    using_space_count->setText("300 ГБ");
    using_space_count->setStyleSheet("border:0px;background-color:white;font: normal 42px;color:#70BBF6;");
    using_space_count->setAlignment(Qt::AlignCenter);

    next_pay_data = new QLabel(bottom_block);
    next_pay_data->setGeometry(453, 198, 160, 43);
    next_pay_data->setText("17.07.21");
    next_pay_data->setStyleSheet("border:0px;background-color:white;font: normal 42px;color:#70BBF6;");
    next_pay_data->setAlignment(Qt::AlignCenter);

    increase_bottom = new QPushButton(bottom_block);
    increase_bottom->setGeometry(104, 299, 200, 46);
    increase_bottom->setText("Увеличить");
    increase_bottom->setStyleSheet("background-color:#F7F9FB;color:#7D7D7D;border:0px;border-radius:10px;");

    out_bottom = new QPushButton(bottom_block);
    out_bottom->setGeometry(424, 299, 200, 46);
    out_bottom->setText("Оплатить");
    out_bottom->setStyleSheet("background-color:#F7F9FB;color:#7D7D7D;border:0px;border-radius:10px;");

    right_block = new QWidget(info_page);
    right_block->setGeometry(756, 0, 320, 944);
    right_block->setStyleSheet("border:0px;border-radius:10px;background-color:white;");

    ava = new QSvgWidget(right_block);
    ava->setGeometry(30, 30, 46, 46);
    ava->setStyleSheet("border:0px;background-color:white;border-radius:23");
    ava->load(QString("../pictures/home_page/ava.svg"));

    out_name_surname = new QLabel(right_block);
    out_name_surname->setGeometry(86, 34, 200, 17);
    out_name_surname->setStyleSheet("border:0px;background-color:white;font: normal 14px;color:#5A5A5A");
    out_name_surname->setText("Фамилия Имя");

    out_email = new QLabel(right_block);
    out_email->setGeometry(86, 56, 200, 14);
    out_email->setStyleSheet("border:0px;background-color:white;color:#C4C4C4;font: normal 13px;");
    out_email->setText("email@gmail.com");

    right_separator = new QSvgWidget(right_block);
    right_separator->setGeometry(30, 106, 260, 1);
    right_separator->setStyleSheet("border:0px;background-color:white");
    right_separator->load(QString("../pictures/home_page/separator.svg"));

    used_space = new QLabel(right_block);
    used_space->setGeometry(30, 136, 213, 20);
    used_space->setStyleSheet("border:0px;background-color:white;color:#7D7D7D;font: normal 14px;");
    used_space->setText("Используемое пространство");

    auto pb_bg = QProgressBar(right_block);
    pb_bg.setStyleSheet("QProgressBar {"
                        "border:0px;"
                        "background-color:#F7F9FB;"
                        "border-radius: 4px;"
                        "}");
    pb_bg.setGeometry(30, 227, 260, 8);
    for(int i = 0; i < 4; i++){
        right_progress_bar[i] = new QProgressBar(right_block);
        switch(i){
            case 0:
                right_progress_bar[i]->setStyleSheet("QProgressBar {"
                                                     "border:0px;"
                                                     "background-color:rgba(0, 0, 0, 0);"
                                                     "border-radius: 4px;"
                                                     "}"
                                                     "QProgressBar::chunk{"
                                                     "background-color: #868FFF;"
                                                     "border:0px;"
                                                     "border-radius: 4px;"
                                                     "}");

                break;
            case 1:
                right_progress_bar[i]->setStyleSheet("QProgressBar {"
                                                     "border:0px;"
                                                     "background-color:rgba(0, 0, 0, 0);"
                                                     "border-radius: 4px;"
                                                     "}"
                                                     "QProgressBar::chunk{"
                                                     "background-color: #59D7AB;"
                                                     "border:0px;"
                                                     "border-radius: 4px;"
                                                     "}");
                break;
            case 2:
                right_progress_bar[i]->setStyleSheet("QProgressBar {"
                                                     "border:0px;"
                                                     "background-color:rgba(0, 0, 0, 0);"
                                                     "border-radius: 4px;"
                                                     "}"
                                                     "QProgressBar::chunk{"
                                                     "background-color: #FF847E;"
                                                     "border:0px;"
                                                     "border-radius: 4px;"
                                                     "}");
                break;
            case 3:
                right_progress_bar[i]->setStyleSheet("QProgressBar {"
                                                     "border:0px;"
                                                     "background-color:rgba(0, 0, 0, 0);"
                                                     "border-radius: 4px;"
                                                     "}"
                                                     "QProgressBar::chunk{"
                                                     "background-color: #FFD75E;"
                                                     "border:0px;"
                                                     "border-radius: 4px;"
                                                     "}");
                break;
        }
        right_progress_bar[i]->setGeometry(30, 227, 260, 8);
        right_progress_bar[i]->setValue(0);
        right_progress_bar[i]->setTextVisible(false);
    }
    right_progress_bar[0]->setValue(25);
    right_progress_bar[1]->setValue(50);
    right_progress_bar[2]->setValue(75);
    right_progress_bar[3]->setValue(80);
    for(int i = 0; i < 3; i++){
        right_progress_bar[i + 1]->stackUnder(right_progress_bar[i]);
    }

    right_gb = new QLabel(right_block);
    right_gb->setGeometry(30, 165, 122, 43);
    right_gb->setStyleSheet("border:0px;background-color:white;color:#5A5A5A;font: normal 36px;");
    right_gb->setText(QString::number(9.23,'g',3) + " ГБ");

    for(int i = 0; i < 4; i++){
        right_names[i] = new QLabel(right_block);
        right_names[i]->setGeometry(91, (256 + (i * (49 + 17))), 50, 17);
        right_names[i]->setStyleSheet("border:0px;background-color:white;font normal 14px;color:#7D7D7D;");
        right_names[i]->setAlignment(Qt::AlignLeft);
    }
    right_names[0]->setText("Файлы");
    right_names[1]->setText("Фото");
    right_names[2]->setText("Видео");
    right_names[3]->setText("Аудио");
    for(int i = 0; i < 4; i++){
        right_buttons[i] = new QPushButton(right_block);
        right_buttons[i]->setGeometry(30, 255 + (i * 66), 46, 46);
        QIcon icon;
        icon.addFile(QString("../pictures/home_page/right_icon_" + QString::number(i) + ".svg"));
        right_buttons[i]->setIcon(icon);
        right_buttons[i]->setIconSize(QSize(30, 30));
    }
    right_buttons[0]->setStyleSheet("border:0px;background-color:rgba(134, 143, 255, 26);border-radius:5px;");
    right_buttons[1]->setStyleSheet("border:0px;background-color:rgba(89, 215, 171, 26);border-radius:5px;");
    right_buttons[2]->setStyleSheet("border:0px;background-color:rgba(255, 147, 141, 26);border-radius:5px;");
    right_buttons[3]->setStyleSheet("border:0px;background-color:rgba(255, 215, 94, 26);border-radius:5px;");
    connect(right_buttons[0], &QCommandLinkButton::clicked, this, &HomePage::on_file_page_clicked);


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

void HomePage::setUsingSpace(size_t space) {
    if(space < 1000000){
        using_space_count->setText(" <1 ГБ");
    }else if((space >= (1e6)) && (space < (999 * 1e6))){
        using_space_count->setText(QString::number(size_t(space / 1e6)) + " ГБ");
    }else if((space >= (999 * 1e6)) && (space < (999 * 1e9))){
        using_space_count->setText(QString::number(size_t(space / 1e6)) + " TБ");
    }
}

void HomePage::on_file_page_clicked() {
    stacked_widget->setCurrentIndex(3);
}


