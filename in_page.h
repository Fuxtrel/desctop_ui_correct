#ifndef DESCTOP_NORM_IN_PAGE_H
#define DESCTOP_NORM_IN_PAGE_H

#include <QPushButton>
#include <QGridLayout>
#include <QResizeEvent>
#include <QLabel>
#include <QtSvg/QtSvg>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include "check_fields.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include "round_graph.h"


class InPage : public QObject{
    Q_OBJECT
public:
    InPage(QWidget *parent = nullptr, QStackedWidget *stacked_widget = nullptr, fux::RoundGraph *rg = nullptr, fux::RoundGraph *rg_ = nullptr, fux::RoundGraph *rg__ = nullptr);
    ~InPage() = default;

    QWidget *in_page;
    QWidget *bg_in_page;
    QLabel *bg_email_input;
    QLabel *bg_password_input;
    QPushButton *check_box_in_page;
    QPushButton *facebook;
    QPushButton *google;
    QPushButton *sign_in;

private:
    fux::RoundGraph *rg;
    fux::RoundGraph *rg_;
    fux::RoundGraph *rg__;
    QStackedWidget* stacked_widget;
    QGridLayout *in_layout;
    QLineEdit *email_input;
    QLineEdit *password_input;
    QLabel *left_title_in_page;
    QLabel *remember_me;
    QSvgWidget *bg_in;
    QSvgWidget *left_separator_in_page;
    QPushButton *forget_password;
    int width_input_fields;
    int height_input_fields;
    QPushButton *hide_password;
    bool check_box_in_page_state;
    bool hide_password_in_page_state;
    QPushButton *registration;
    QString email;
    QString password;
    QSvgWidget *warning;
    QLabel *warning_text;


private slots:
    void on_check_box_in_page_clicked();
    void on_forget_password_clicked();
    void on_hide_password_clicked();
    void on_sign_in_clicked();
    void on_password_input_edit();
    void on_email_input_edit();
    void on_registration_clicked();
};


#endif //DESCTOP_NORM_IN_PAGE_H
