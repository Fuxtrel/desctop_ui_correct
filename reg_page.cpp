#include "reg_page.h"

RegPage::RegPage(QWidget *parent, QStackedWidget *stacked_widget) {
    this->stacked_widget = stacked_widget;
    bg_reg_page = new QWidget(parent);
    bg_reg_page->setStyleSheet("background-color:#F7F9FB;");

    reg_page = new QWidget(bg_reg_page);
    reg_page->setGeometry(300, 300, 1280, 780);
    reg_page->setFixedSize(1280, 780);
    reg_page->setStyleSheet("border:0px;border-radius:15px;background-color:white;");
    reg_layout = new QGridLayout(bg_reg_page);
    reg_layout->addWidget(reg_page, 1, 1, Qt::AlignCenter);
    reg_layout->setMargin(0);

    right_title = new QLabel(reg_page);
    right_title->setGeometry(820, 125, 199, 44);
    right_title->setStyleSheet("background-color:white;border:0px;");
    right_title->setAlignment(Qt::AlignCenter);
    right_title->setText("Регистрация");

    width_input_fields = 480;
    height_input_fields = 60;

    bg_fio_input = new QLabel(reg_page);
    bg_fio_input->setGeometry(QRect(680, 240, width_input_fields, height_input_fields));
    bg_fio_input->setStyleSheet("background-color: white;border:0px;border-radius: 15;");

    fio_input = new QLineEdit(reg_page);
    fio_input->setGeometry(
            QRect(bg_fio_input->geometry().x() + 25, bg_fio_input->geometry().y() + 10, width_input_fields - 45,
                  height_input_fields - 20));
    fio_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "Имя пользователя", nullptr));
    fio_input->setStyleSheet("background-color: white;border:0px;");
    fio_input->setFrame(false);
    connect(fio_input, &QLineEdit::textChanged, this, &RegPage::on_fio_input_edit);

    bg_email_input = new QLabel(reg_page);
    bg_email_input->setGeometry(QRect(680, 320, width_input_fields, height_input_fields));
    bg_email_input->setStyleSheet("background-color: white;border:0px;border-radius: 15;");

    email_input = new QLineEdit(reg_page);
    email_input->setGeometry(
            QRect(bg_email_input->geometry().x() + 25, bg_email_input->geometry().y() + 10, width_input_fields - 45,
                  height_input_fields - 20));
    email_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email", nullptr));
    email_input->setStyleSheet("background-color: white;border-color: rgba(0,0,0,0);");
    email_input->setFrame(false);
    connect(email_input, &QLineEdit::textChanged, this, &RegPage::on_email_input_edit);

    bg_password_input = new QLabel(reg_page);
    bg_password_input->setGeometry(QRect(680, 400, width_input_fields, height_input_fields));
    bg_password_input->setStyleSheet("background-color: white;border:0px;border-radius: 15;");

    password_input = new QLineEdit(reg_page);
    password_input->setGeometry(
            QRect(bg_password_input->geometry().x() + 25, bg_password_input->geometry().y() + 10, width_input_fields - 45,
                  height_input_fields - 20));
    password_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "Пароль", nullptr));
    password_input->setStyleSheet("background-color: white;border-color: rgba(0,0,0,0);");
    password_input->setEchoMode(QLineEdit::Password);
    password_input->setFrame(false);
    connect(password_input, &QLineEdit::textChanged, this, &RegPage::on_password_input_edit);

    check_box_reg_page_state = false;
    check_box_reg_page = new QPushButton(reg_page);
    check_box_reg_page->setGeometry(680, 480, 20, 20);
    check_box_reg_page->setStyleSheet("background-color:white;border-radius:6px;");
    connect(check_box_reg_page, &QPushButton::clicked, this, &RegPage::on_check_box_reg_page_clicked);

    hide_password = new QPushButton(reg_page);
    hide_password->setGeometry(1103, 414, 32, 32);
    QIcon hide_password_off;
    hide_password_off.addFile(QString::fromUtf8("../pictures/in_page/eye_.svg"), QSize(), QIcon::Normal,
                              QIcon::On);
    hide_password->setIconSize(QSize(32, 32));
    hide_password->setIcon(hide_password_off);
    hide_password->setAutoFillBackground(true);
    hide_password->setStyleSheet("border:0px;background-color:white;");
    connect(hide_password, &QPushButton::clicked, this, &RegPage::on_hide_password_clicked);
    hide_password_reg_page_state = false;

    warning_fio = new QSvgWidget(reg_page);
    warning_fio->setGeometry(680, 549, 25, 25);
    warning_fio->setStyleSheet("border:0px;");
    warning_fio->load(QString("../pictures/in_page/warning.svg"));
    warning_fio->hide();

    warning_email = new QSvgWidget(reg_page);
    warning_email->setGeometry(680, 579, 25, 25);
    warning_email->setStyleSheet("border:0px;");
    warning_email->load(QString("../pictures/in_page/warning.svg"));
    warning_email->hide();

    warning_password = new QSvgWidget(reg_page);
    warning_password->setGeometry(680, 609, 25, 25);
    warning_password->setStyleSheet("border:0px;");
    warning_password->load(QString("../pictures/in_page/warning.svg"));
    warning_password->hide();

    warning_fio_text = new QLabel(reg_page);
    warning_fio_text->setGeometry(715, 549, 402, 25);
    warning_fio_text->setStyleSheet("border:0px;background-color:white;");
    warning_fio_text->setText("Не оставляйте поле \"имя пользователя\" пустым");
    warning_fio_text->hide();

    warning_email_text = new QLabel(reg_page);
    warning_email_text->setGeometry(715, 579, 402, 25);
    warning_email_text->setStyleSheet("border:0px;background-color:white;");
    warning_email_text->setText("Некорректный email");
    warning_email_text->hide();

    warning_password_text = new QLabel(reg_page);
    warning_password_text->setGeometry(715, 609, 402, 25);
    warning_password_text->setStyleSheet("border:0px;background-color:white;");
    warning_password_text->setText("Пароль должен содержать не менее 8 символов");
    warning_password_text->hide();

    registration = new QPushButton(reg_page);
    registration->setGeometry(755, 650, 330, 60);
    registration->setStyleSheet("border:0px;border-radius:15px;color:background:#C4C4C4;");
    registration->setText("Зарегистрироваться");
    connect(registration, &QPushButton::clicked, this, &RegPage::on_registration_clicked);

}

QWidget *RegPage::getLinkBgRegPage() {
    return bg_reg_page;
}

void RegPage::on_check_box_reg_page_clicked() {
    QIcon check_point_on, check_point_off;
    check_point_on.addFile(QString::fromUtf8("../pictures/reg_page/check_mark.svg"), QSize(), QIcon::Normal,
                           QIcon::On);
    check_box_reg_page->setIconSize(QSize(14, 16));
    if (!check_box_reg_page_state) {
        check_box_reg_page_state = true;
        check_box_reg_page->setIcon(check_point_on);
    } else {
        check_box_reg_page_state = false;
        check_box_reg_page->setIcon(check_point_off);
    }
}

void RegPage::on_hide_password_clicked() {
    QIcon icon;
    if (!hide_password_reg_page_state) {
        icon.addFile(QString::fromUtf8("../pictures/in_page/eye.svg"), QSize(), QIcon::Normal, QIcon::On);
        hide_password_reg_page_state = true;
        password_input->setEchoMode(QLineEdit::Normal);
    } else if (hide_password_reg_page_state) {
        icon.addFile(QString::fromUtf8("../pictures/in_page/eye_.svg"), QSize(), QIcon::Normal, QIcon::On);
        hide_password_reg_page_state = false;
        password_input->setEchoMode(QLineEdit::Password);
    }
    hide_password->setIcon(icon);
}

void RegPage::on_registration_clicked() {
    CheckFields check_fields(fio_input, email_input, password_input);
    qDebug() << check_fields.isFioEmailPasswordCorrect();
    if(check_fields.isFioEmailPasswordCorrect()[0] == '0'){
        warning_fio->hide();
        warning_fio_text->hide();
    } else {
        warning_fio->show();
        warning_fio_text->show();
    }
    if(check_fields.isFioEmailPasswordCorrect()[1] == '0'){
        warning_email->hide();
        warning_email_text->hide();
    }else{
        warning_email->show();
        warning_email_text->show();
    }
    if(check_fields.isFioEmailPasswordCorrect()[1] == '0'){
        warning_password->hide();
        warning_password_text->hide();
    }else{
        warning_password->show();
        warning_password_text->show();
    }
    if(check_fields.isFioEmailPasswordCorrect() == "000"){
        registration->setDisabled(false);
        registration->setStyleSheet("border:0px;border-radius:15px;color:#64AEEA;");
    }else{
        registration->setStyleSheet("border:0px;border-radius:15px;color:#C4C4C4;;");
    }
}

void RegPage::on_password_input_edit() {
    CheckFields check_fields(fio_input, email_input, password_input);
    qDebug() << check_fields.isFioEmailPasswordCorrect();
    if(check_fields.isFioEmailPasswordCorrect()[2] == '0'){
        warning_password->hide();
        warning_password_text->hide();
    }else{
        warning_password->show();
        warning_password_text->show();
    }
    if(check_fields.isFioEmailPasswordCorrect() == "000"){
        registration->setDisabled(false);
        registration->setStyleSheet("border:0px;border-radius:15px;color:#64AEEA;");
    }
}

void RegPage::on_email_input_edit() {
    CheckFields check_fields(fio_input, email_input, password_input);
    qDebug() << check_fields.isFioEmailPasswordCorrect();
    if(check_fields.isFioEmailPasswordCorrect()[1] == '0'){
        warning_email->hide();
        warning_email_text->hide();
    }else{
        warning_email->show();
        warning_email_text->show();
    }
    if(check_fields.isFioEmailPasswordCorrect() == "000"){
        registration->setDisabled(false);
        registration->setStyleSheet("border:0px;border-radius:15px;color:#64AEEA;");
    }
}

void RegPage::on_fio_input_edit() {
    CheckFields check_fields(fio_input, email_input, password_input);
    qDebug() << check_fields.isFioEmailPasswordCorrect();
    if(check_fields.isFioEmailPasswordCorrect()[0] == '0'){
        warning_fio->hide();
        warning_fio_text->hide();
    } else {
        warning_fio->show();
        warning_fio_text->show();
    }
    if(check_fields.isFioEmailPasswordCorrect() == "000"){
        registration->setDisabled(false);
        registration->setStyleSheet("border:0px;border-radius:15px;color:#64AEEA;");
    }
}
