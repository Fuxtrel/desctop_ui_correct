#ifndef DESCTOP_NORM_IN_PAGE_H
#define DESCTOP_NORM_IN_PAGE_H

#include <QPushButton>
#include <QGridLayout>
#include <QResizeEvent>
#include <QLabel>
#include <QtSvg/QtSvg>


class InPage : public QObject{
    Q_OBJECT
public:
    InPage(QWidget *parent = nullptr, QStackedWidget *stacked_widget = nullptr);
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

    QStackedWidget* stacked_widget;
    QGridLayout *in_layout;
    QLineEdit *email_input;
    QLineEdit *password_input;
    QLabel *left_title_in_page;
    QLabel *right_title_in_page;
    QLabel *right_subtitle_in_page;
    QLabel *remember_me;
    QSvgWidget *left_circle_title_in_page;
    QSvgWidget *left_separator_in_page;
    QPushButton *forget_password;
    int width_input_fields;
    int height_input_fields;
    QPushButton *hide_password;
    bool check_box_in_page_state;
    bool hide_password_in_page_state;


private slots:
    void on_check_box_in_page_clicked();
    void on_forget_password_clicked();
    void on_hide_password_clicked();

};


#endif //DESCTOP_NORM_IN_PAGE_H
