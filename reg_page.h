#ifndef DESCTOP_NORM_REG_PAGE_H
#define DESCTOP_NORM_REG_PAGE_H

#include <QPushButton>
#include <QGridLayout>
#include <QResizeEvent>
#include <QLabel>
#include <QtSvg/QtSvg>
#include "check_fields.h"

class RegPage : public QObject{
    Q_OBJECT
public:
    RegPage(QWidget *parent = nullptr, QStackedWidget *stacked_widget = nullptr);
    ~RegPage() = default;
    QWidget* getLinkBgRegPage();
    QWidget *reg_page;
    QLabel *bg_email_input;
    QLabel *bg_password_input;
    QLabel *bg_fio_input;
    QPushButton *check_box_reg_page;
    QPushButton *registration;
private:
    QStackedWidget* stacked_widget;
    QWidget *bg_reg_page;
    QGridLayout *reg_layout;
    QLabel *right_title;
    QLineEdit *email_input;
    QLineEdit *password_input;
    QLineEdit *fio_input;
    int width_input_fields;
    int height_input_fields;
    QPushButton *hide_password;
    bool check_box_reg_page_state;
    bool hide_password_reg_page_state;

    QLabel *warning_fio_text;
    QLabel *warning_email_text;
    QLabel *warning_password_text;
    QSvgWidget *warning_fio;
    QSvgWidget *warning_email;
    QSvgWidget *warning_password;



private slots:
    void on_check_box_reg_page_clicked();
    void on_hide_password_clicked();
    void on_registration_clicked();
    void on_password_input_edit();
    void on_email_input_edit();
    void on_fio_input_edit();
};

#endif //DESCTOP_NORM_REG_PAGE_H
