#ifndef DESCTOP_NORM_IN_PAGE_H
#define DESCTOP_NORM_IN_PAGE_H

#include <QPushButton>
#include <QGridLayout>
#include <QResizeEvent>
#include <QLabel>
#include <QtSvg/QtSvg>


class InPage {

public:
    InPage(QWidget *parent = nullptr);
    ~InPage() = default;
    QWidget* getLinkBgInPage();
    QLabel* getLinkBgEmailInputInPage();
    QLabel* getLinkBgPasswordInputInPage();
private:
    QWidget *bg_in_page;
    QWidget *in_page;
    QGridLayout *in_layout;

    QLabel *left_title_in_page;
    QLabel *right_title_in_page;
    QLabel *right_subtitle_in_page;

    QSvgWidget *left_circle_title_in_page;
    QSvgWidget *left_separator_in_page;
    QPushButton *check_box_in_page;

    int width_input_fields;
    int height_input_fields;
    QLineEdit *email_input;
    QLineEdit *password_input;
    QLabel *bg_email_input;
    QLabel *bg_password_input;
};


#endif //DESCTOP_NORM_IN_PAGE_H
