#include "in_page.h"

InPage::InPage(QWidget *parent) {
    bg_in_page = new QWidget(parent);
    bg_in_page->setStyleSheet("background-color:#F7F9FB;");

    in_page = new QWidget(bg_in_page);
    in_page->setGeometry(300, 3000, 300, 300);
    in_page->setFixedSize(1280, 780);
    in_layout = new QGridLayout(bg_in_page);
    in_layout->addWidget(in_page, 1, 1, Qt::AlignCenter);

    left_title_in_page = new QLabel(in_page);
    left_title_in_page->setGeometry(180, 150, 361, 44);
    left_title_in_page->setAlignment(Qt::AlignCenter);
    left_title_in_page->setText("Вход в учётную запись");

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


}

QWidget *InPage::getLinkBgInPage() {
    return bg_in_page;
}

QLabel *InPage::getLinkBgEmailInputInPage() {
    return bg_email_input;
}

QLabel *InPage::getLinkBgPasswordInputInPage() {
    return bg_password_input;
}
