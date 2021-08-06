#include "in_page.h"

InPage::InPage(QWidget *parent, QStackedWidget *stacked_widget, fux::RoundGraph *rg, fux::RoundGraph *rg_, fux::RoundGraph *rg__):rg(rg), rg_(rg_), rg__(rg__) {
    this->stacked_widget = stacked_widget;
    bg_in_page = new QWidget(parent);
    bg_in_page->setStyleSheet("background-color:#F7F9FB;");

    in_page = new QWidget(bg_in_page);
    in_page->setGeometry(300, 300, 1280, 780);
    in_page->setFixedSize(1280, 780);
    in_page->setStyleSheet("border:0px;border-radius:15px;background-color:white;");
    in_layout = new QGridLayout(bg_in_page);
    in_layout->addWidget(in_page, 1, 1, Qt::AlignCenter);
    in_layout->setMargin(0);

    bg_in = new QSvgWidget(in_page);
    bg_in->setGeometry(0, 0, 1280, 780);
    bg_in->setStyleSheet("border:0px");
    bg_in->load(QString("../pictures/in_page/bg_in.svg"));

    left_separator_in_page = new QSvgWidget(in_page);
    left_separator_in_page->setGeometry(120, 459, 480, 27);
    left_separator_in_page->setStyleSheet("border:0px;background-color:white;");
    left_separator_in_page->load(QString("../pictures/in_page/separator.svg"));

    left_title_in_page = new QLabel(in_page);
    left_title_in_page->setGeometry(180, 150, 361, 44);
    left_title_in_page->setAlignment(Qt::AlignCenter);
    left_title_in_page->setText("Вход в учётную запись");
    left_title_in_page->setStyleSheet("color:#7D7D7D;background-color:white;");

    //Ввод емейла в действительное поле
    width_input_fields = 480;
    height_input_fields = 60;

    bg_email_input = new QLabel(in_page);
    bg_email_input->setAutoFillBackground(false);
    bg_email_input->setGeometry(QRect(120, 244, width_input_fields, height_input_fields));
    bg_email_input->setStyleSheet("background-color: white;border:0px;border-radius: 15;");

    email_input = new QLineEdit(in_page);
    email_input->setGeometry(
            QRect(bg_email_input->geometry().x() + 25, bg_email_input->geometry().y() + 10, width_input_fields - 45,
                  height_input_fields - 20));
    email_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email", nullptr));
    email_input->setStyleSheet("background-color: white;border-color: rgba(0,0,0,0);");
    email_input->setFrame(false);
    //Ввод емейла в действительное поле

    //Ввод пароля в действительное поле
    bg_password_input = new QLabel(in_page);
    bg_password_input->setGeometry(QRect(120, 324, width_input_fields, height_input_fields));
    bg_password_input->setStyleSheet("background-color: white;border:0px;border-radius: 15;");

    password_input = new QLineEdit(in_page);
    password_input->setGeometry(QRect(bg_password_input->geometry().x() + 25, bg_password_input->geometry().y() + 10,
                                      width_input_fields - 45, height_input_fields - 20));
    password_input->setEchoMode(QLineEdit::Password);
    password_input->setPlaceholderText("Пароль");
    password_input->setStyleSheet("background-color: white;border-color: rgba(0,0,0,0);");
    password_input->setFrame(false);
    //Ввод пароля в действительное поле

    check_box_in_page = new QPushButton(in_page);
    check_box_in_page->setGeometry(120, 407, 20, 20);
    check_box_in_page->setStyleSheet("border:0px;border-radius:6px;background-color:white;");
    check_box_in_page_state = false;
    connect(check_box_in_page, &QPushButton::clicked, this, &InPage::on_check_box_in_page_clicked);

    remember_me = new QLabel(in_page);
    remember_me->setGeometry(150, 404, 165, 27);
    remember_me->setText("Запомнить меня");
    remember_me->setStyleSheet("color:#7D7D7D;background-color:white;");

    forget_password = new QPushButton(in_page);
    forget_password->setGeometry(454, 404, 146, 25);
    forget_password->setText("Забыли пароль?");
    forget_password->setStyleSheet("border:0px;text-decoration: underline;color:#7D7D7D;background-color:white;");
    connect(forget_password, &QPushButton::clicked, this, &InPage::on_forget_password_clicked);

    hide_password = new QPushButton(in_page);
    hide_password->setGeometry(543, 338, 32, 32);

    QIcon hide_password_off;
    hide_password_off.addFile(QString::fromUtf8("../pictures/in_page/eye_.svg"), QSize(), QIcon::Normal,
                              QIcon::On);
    hide_password->setIconSize(QSize(32, 32));
    hide_password->setIcon(hide_password_off);
    hide_password->setAutoFillBackground(true);
    hide_password->setStyleSheet("border:0px;background-color:white;");
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
    sign_in->setStyleSheet("border:0px;border-radius:15px;color:#7D7D7D;background-color:white;");
    sign_in->setText("Войти");
    sign_in->setDisabled(true);
    connect(sign_in, &QPushButton::clicked, this, &InPage::on_sign_in_clicked);
    connect(password_input, &QLineEdit::textChanged, this, &InPage::on_password_input_edit);
    connect(email_input, &QLineEdit::textChanged, this, &InPage::on_email_input_edit);

    registration = new QPushButton(in_page);
    registration->setGeometry(833, 650, 333, 60);
    registration->setStyleSheet("border:0px;border-radius:15px;color:#64AEEA;");
    registration->setText("Зарегистироваться");
    connect(registration, &QPushButton::clicked, this, &InPage::on_registration_clicked);

    warning = new QSvgWidget(in_page);
    warning->setGeometry(120, 610, 25, 25);
    warning->setStyleSheet("border:0px;");
    warning->load(QString("../pictures/in_page/warning.svg"));
    warning->hide();

    warning_text = new QLabel(in_page);
    warning_text->setGeometry(155, 610, 362, 25);
    warning_text->setStyleSheet("border:0px;background-color:white;");
    warning_text->setText("Неверный email или пароль");
    warning_text->hide();

    QFile personal_data("./personal_data");
    personal_data.open(QIODevice::ReadOnly);
    QString data = personal_data.readAll();
    personal_data.close();
    QJsonDocument document = QJsonDocument::fromJson(QString(data).toUtf8());
    QJsonObject json = document.object();
    if(json["check_box"].toBool()){
        email = json["email"].toString();
        password = json["password"].toString();
        QIcon check_point_on;
        check_point_on.addFile(QString::fromUtf8("../pictures/in_page/check_box_point.svg"), QSize(), QIcon::Normal,
                               QIcon::On);
        check_box_in_page->setIconSize(QSize(8, 8));
        check_box_in_page->setIcon(check_point_on);
        check_box_in_page_state = json["check_box"].toBool();
    }
    if((!email.isEmpty()) && (!password.isEmpty())){
        email_input->setText(email);
        password_input->setText(password);
    }
}

void InPage::on_check_box_in_page_clicked() {
    QIcon check_point_on, check_point_off;
    check_point_on.addFile(QString::fromUtf8("../pictures/reg_page/check_mark.svg"), QSize(), QIcon::Normal,
                           QIcon::On);
    check_box_in_page->setIconSize(QSize(14, 16));
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
    } else if (hide_password_in_page_state) {
        icon.addFile(QString::fromUtf8("../pictures/in_page/eye_.svg"), QSize(), QIcon::Normal, QIcon::On);
        hide_password_in_page_state = false;
        password_input->setEchoMode(QLineEdit::Password);
    }
    hide_password->setIcon(icon);
}

void InPage::on_forget_password_clicked() {
    stacked_widget->setCurrentIndex(3);
}

void InPage::on_sign_in_clicked() {
    CheckFields check_fields(email_input, password_input);
    if (check_fields.isEmailPasswordCorrect() == 0) {
        warning->hide();
        warning_text->hide();
        email = email_input->text();
        password = password_input->text();
        if(check_box_in_page_state) {
            QFile file("./personal_data");
            if (!file.isOpen()) {
                file.open(QIODevice::WriteOnly);
            } else {
                qDebug() << "Файл для записи личных данных уже открыт";
            }
            QJsonObject js;
            js["email"] = email;
            js["password"] = password;
            js["check_box"] = check_box_in_page_state;
            QJsonDocument doc(js);
            QByteArray data = doc.toJson();
            file.write(data);
            file.close();
        }else{
            QFile file("./personal_data");
            if (!file.isOpen()) {
                file.open(QIODevice::WriteOnly);
            } else {
                qDebug() << "Файл для записи личных данных уже открыт";
            }
        }

        /*QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
        const QUrl url(QStringLiteral("https://upstorage.net/api/auth/sign-in"));
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QJsonObject obj;
        obj["email"] = email;
        obj["password"] = password;
        obj["invitationToken"] = "";
        obj["tenantId"] = "";
        QJsonDocument document(obj);
        QByteArray data_ = document.toJson();
        QNetworkReply *reply = mgr->post(request, data_);
        QObject::connect(reply, &QNetworkReply::finished, [=]() {
            if (reply->error() == QNetworkReply::NoError) {
                QString contents = QString::fromUtf8(reply->readAll());
                qDebug() << contents;
            } else {
                QString contents = QString::fromUtf8(reply->readAll());
                QString err = reply->errorString();
                qDebug() << err;
            }
            reply->deleteLater();
        });*/
        rg->setLoadPercent(0);
        rg_->setLoadPercent(0);
        rg__->setLoadPercent(0);
        rg->setLoadPercent(90);
        rg_->setLoadPercent(100);
        rg__->setLoadPercent(90);
        stacked_widget->setCurrentIndex(2);
    } else if((check_fields.isEmailPasswordCorrect() == 1) || (check_fields.isEmailPasswordCorrect() == 2) || (check_fields.isEmailPasswordCorrect() == 3)){
        warning = new QSvgWidget(in_page);
        warning->setGeometry(120, 610, 25, 25);
        warning->setStyleSheet("border:0px;");
        warning->load(QString("../pictures/in_page/warning.svg"));

        warning_text = new QLabel(in_page);
        warning_text->setGeometry(155, 610, 362, 25);
        warning_text->setStyleSheet("border:0px;background-color:white;");
        warning_text->setText("Неверный email или пароль");
    }


}

void InPage::on_password_input_edit() {
    CheckFields check_fields(email_input, password_input);
    if (check_fields.isEmailPasswordCorrect() == 0) {
        sign_in->setDisabled(false);
        warning->hide();
        warning_text->hide();
        sign_in->setStyleSheet("border:0px;border-radius:15px;color:#64AEEA;background-color:white;");
    }else if((check_fields.isEmailPasswordCorrect() == 1) || (check_fields.isEmailPasswordCorrect() == 2) || (check_fields.isEmailPasswordCorrect() == 3)){
        warning->show();
        warning_text->show();
    }
}

void InPage::on_email_input_edit() {
    CheckFields check_fields(email_input, password_input);
    if (check_fields.isEmailPasswordCorrect() == 0) {
        sign_in->setDisabled(false);
        warning->hide();
        warning_text->hide();
        sign_in->setStyleSheet("border:0px;border-radius:15px;color:#64AEEA;background-color:white;");
    }else if((check_fields.isEmailPasswordCorrect() == 1) || (check_fields.isEmailPasswordCorrect() == 2) || (check_fields.isEmailPasswordCorrect() == 3)){
        warning->show();
        warning_text->show();
    }
}

void InPage::on_registration_clicked() {
    stacked_widget->setCurrentIndex(0);
}




