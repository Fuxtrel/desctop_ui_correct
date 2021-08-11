#ifndef DESCTOP_NORM_HOME_PAGE_H
#define DESCTOP_NORM_HOME_PAGE_H

#include <QPushButton>
#include <QGridLayout>
#include <QResizeEvent>
#include <QLabel>
#include <QtSvg/QtSvg>
#include <QProgressBar>
#include <QScrollArea>

class HomePage : public QObject {
Q_OBJECT

public:
    HomePage(QWidget *parent = nullptr, QStackedWidget *stacked_widget = nullptr);

    ~HomePage() = default;

    void setUsingSpace(size_t space);

    QWidget *bg_home_page;
    QWidget *top_block;
    QLabel *space_load;
    QProgressBar *bottom_progress_bar;
    QLabel *out_name_surname;
    QLabel *out_email;
    QStackedWidget *stacked_widget_home;
    QWidget *template_bg;

private:
    QWidget *home_page;
    QGridLayout *home_layout;
    QWidget *left_buttons_group;
    QSvgWidget *logo;
    QSvgWidget *separator;
    QCommandLinkButton *buttons[8];
    bool buttons_state[8] = {false};
    QSvgWidget *separator_b;
    QLabel *last_files;
    QStackedWidget *stacked_widget;
    QWidget *info_page;
    QLabel *place_on_your;
    QLabel *rent_place;

    QSvgWidget *separators[2];
    QLabel *money[2];
    QPushButton *increase;
    QPushButton *out;
    QLabel *you_rent_out;
    QSvgWidget *top_separator;

    QWidget *bottom_block;
    QLabel *you_rent;
    QSvgWidget *bottom_separator;
    QLabel *space_is_full;
    QLabel *sign_progress_bar[3];
    QLabel *using_space;
    QLabel *next_pay;
    QLabel *every_day_pay;
    QLabel *your_balance;
    QLabel *using_space_count;
    QLabel *next_pay_data;
    QPushButton *increase_bottom;
    QPushButton *out_bottom;

    QWidget *right_block;
    QSvgWidget *ava;
    QSvgWidget *right_separator;
    QLabel *used_space;
    QLabel *right_gb;
    QLabel *from;
    QLabel *full_right_gb;
    QProgressBar *right_progress_bar[4];
    QLabel *right_names[4];
    QPushButton *right_buttons[4];


    QGridLayout *template_bg_layout;
    QWidget *files_page;


    void setButtonsDefault();

private slots:
    void on_command_link_button_0_push();
    void on_command_link_button_1_push();
    void on_command_link_button_2_push();
    void on_command_link_button_3_push();
    void on_command_link_button_4_push();
    void on_command_link_button_5_push();
    void on_command_link_button_6_push();
    void on_command_link_button_7_push();

};


#endif //DESCTOP_NORM_HOME_PAGE_H
