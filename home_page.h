#ifndef DESCTOP_NORM_HOME_PAGE_H
#define DESCTOP_NORM_HOME_PAGE_H

#include <QPushButton>
#include <QGridLayout>
#include <QResizeEvent>
#include <QLabel>
#include <QtSvg/QtSvg>

class HomePage : public QObject {
Q_OBJECT

public:
    HomePage(QWidget *parent = nullptr, QStackedWidget *stacked_widget = nullptr);

    ~HomePage() = default;

    QWidget *bg_home_page;
    QWidget *top_block;
private:
    QGraphicsDropShadowEffect *effect;
    QStackedWidget *stacked_widget;
    QWidget *home_page;
    QGridLayout *home_layout;
    QWidget *left_buttons_group;
    QSvgWidget *logo;
    QSvgWidget *separator;
    QCommandLinkButton *buttons[8];
    bool buttons_state[8] = {false};
    QSvgWidget *separator_b;
    QLabel *last_files;
    QStackedWidget *stacked_widget_home;
    QWidget *info_page;

    QWidget *bottom_block;
    QWidget *right_block;


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
