#include "in_page.h"

InPage::InPage(QWidget *parent, QStackedWidget *stacked_widget) {
    this->stacked_widget = stacked_widget;
    bg_in_page = new QWidget(parent);
    bg_in_page->setStyleSheet("background-color:#F7F9FB;");

    in_page = new QWidget(bg_in_page);
    in_page->setGeometry(300, 300, 1280, 780);
    in_page->setFixedSize(1280, 780);
    in_page->setStyleSheet("border:0px;border-radius:15px");
    in_layout = new QGridLayout(bg_in_page);
    in_layout->addWidget(in_page, 1, 1, Qt::AlignCenter);

    left_circle_title_in_page = new QSvgWidget(in_page);
    left_circle_title_in_page->setGeometry(0, 0, 1280, 780);
    left_circle_title_in_page->setStyleSheet("border:0px");
    left_circle_title_in_page->load(QString("../pictures/in_page/bg_in.svg"));


    left_title_in_page = new QLabel(in_page);
    left_title_in_page->setGeometry(180, 150, 361, 44);
    left_title_in_page->setAlignment(Qt::AlignCenter);
    left_title_in_page->setText("Вход в учётную запись");
    left_title_in_page->setStyleSheet("color:#7D7D7D;");

    //Ввод емейла в действительное поле
    width_input_fields = 480;
    height_input_fields = 60;
    bg_email_input = new QLabel(in_page);
    bg_email_input->setAutoFillBackground(false);
    bg_email_input->setGeometry(QRect(120, 244, width_input_fields, height_input_fields));
    bg_email_input->setStyleSheet("background-color: white;border:0px;border-radius: 15;");

    email_input = new QLineEdit(in_page);
    email_input->setObjectName(QString::fromUtf8("email_input"));
    email_input->setGeometry(
            QRect(bg_email_input->geometry().x() + 25, bg_email_input->geometry().y() + 10, width_input_fields - 45,
                  height_input_fields - 20));
    email_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email", nullptr));
    email_input->setStyleSheet("background-color: white;border-color: rgba(0,0,0,0);");
    email_input->setFrame(false);
    //Ввод емейла в действительное поле

    //Ввод пароля в действительное поле
    bg_password_input = new QLabel(in_page);
    bg_password_input->setObjectName(QString::fromUtf8("bg_password_input"));
    bg_password_input->setGeometry(QRect(120, 324, width_input_fields, height_input_fields));
    bg_password_input->setStyleSheet("background-color: white;border:0px;border-radius: 15;");

    password_input = new QLineEdit(in_page);
    password_input->setObjectName(QString::fromUtf8("password_input"));
    password_input->setGeometry(QRect(bg_password_input->geometry().x() + 25, bg_password_input->geometry().y() + 10,
                                      width_input_fields - 45, height_input_fields - 20));
    password_input->setEchoMode(QLineEdit::Password);
    password_input->setPlaceholderText("Пароль");
    password_input->setStyleSheet("background-color: white;border-color: rgba(0,0,0,0);");
    password_input->setFrame(false);
    //Ввод пароля в действительное поле

    check_box_in_page = new QPushButton(in_page);
    check_box_in_page->setGeometry(120, 407, 20, 20);
    check_box_in_page->setStyleSheet("border:0px;border-radius:6px");
    check_box_in_page_state = false;
    connect(check_box_in_page, &QPushButton::clicked, this, &InPage::on_check_box_in_page_clicked);

    remember_me = new QLabel(in_page);
    remember_me->setGeometry(150, 404, 165, 27);
    remember_me->setText("Запомнить меня");
    remember_me->setStyleSheet("color:#7D7D7D;");

    forget_password = new QPushButton(in_page);
    forget_password->setGeometry(454, 404, 146, 25);
    forget_password->setText("Забыли пароль?");
    forget_password->setStyleSheet("border:0px;text-decoration: underline;color:#7D7D7D;");
    connect(forget_password, &QPushButton::clicked, this, &InPage::on_forget_password_clicked);

    hide_password = new QPushButton(in_page);
    hide_password->setGeometry(543, 338, 32, 32);

    QIcon hide_password_off;
    hide_password_off.addFile(QString::fromUtf8("../pictures/in_page/eye_.svg"), QSize(), QIcon::Normal,
                           QIcon::On);
    hide_password->setIconSize(QSize(32, 32));
    hide_password->setIcon(hide_password_off);
    hide_password->setAutoFillBackground(true);
    hide_password->setStyleSheet("border:0px;");
    connect(hide_password, &QPushButton::clicked, this, &InPage::on_hide_password_clicked);
    hide_password_in_page_state = false;

    facebook = new QPushButton(in_page);
    facebook->setGeometry(287, 511, 60, 60);
    facebook->setStyleSheet("border:0px;border-radius:30px;");
    QIcon facebook_icon;
    facebook_icon.addFile("../pictures/in_page/facebook.svg");
    facebook->setIconSize(QSize(17, 36));
    facebook->setIcon(facebook_icon);

    google = new QPushButton(in_page);
    google->setGeometry(372, 511, 60, 60);
    google->setStyleSheet("border:0px;border-radius:30px;");
    QIcon google_icon;
    google_icon.addFile("../pictures/in_page/google.svg");
    google->setIconSize(QSize(36, 36));
    google->setIcon(google_icon);

    sign_in = new QPushButton(in_page);
    sign_in->setGeometry(193, 650, 333, 60);
    sign_in->setStyleSheet("border:0px;border-radius:15px;color:#7D7D7D;");
    sign_in->setText("Войти");




}

void InPage::on_check_box_in_page_clicked() {
    QIcon check_point_on, check_point_off;
    check_point_on.addFile(QString::fromUtf8("../pictures/in_page/check_box_point.svg"), QSize(), QIcon::Normal,
                           QIcon::On);
    check_box_in_page->setIconSize(QSize(8, 8));
    if (!check_box_in_page_state) {
        check_box_in_page_state = true;
        check_box_in_page->setIcon(check_point_on);
    } else {
        check_box_in_page_state = false;
        check_box_in_page->setIcon(check_point_off);
    }
}

void InPage::on_hide_password_clicked() {
    QIcon icon;
    if (!hide_password_in_page_state) {
        icon.addFile(QString::fromUtf8("../pictures/in_page/eye.svg"), QSize(), QIcon::Normal, QIcon::On);
        hide_password_in_page_state = true;
        password_input->setEchoMode(QLineEdit::Normal);
    } else if(hide_password_in_page_state){
        icon.addFile(QString::fromUtf8("../pictures/in_page/eye_.svg"), QSize(), QIcon::Normal, QIcon::On);
        hide_password_in_page_state = false;
        password_input->setEchoMode(QLineEdit::Password);
    }
    hide_password->setIcon(icon);
}

void InPage::on_forget_password_clicked() {
    stacked_widget->setCurrentIndex(3);
}



