#ifndef DESCTOP_NORM_FILE_PAGE_H
#define DESCTOP_NORM_FILE_PAGE_H

#include <QObject>
#include <QStackedWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QCommandLinkButton>
#include <QSvgWidget>
#include <QGroupBox>
#include <QLabel>

class FilePage : public QObject {
    Q_OBJECT
public:
    FilePage(QWidget *parent = nullptr, QStackedWidget *stacked_widget = nullptr);
    ~FilePage() = default;
    QWidget *bg_file_page;
    QCommandLinkButton *buttons[8];
    std::vector<bool> buttons_state = {false, false, false, false, false, false, false};
private:
    QSvgWidget *logo;
    QStackedWidget *stacked_widget;

    QWidget *left_buttons_block;
    QGridLayout *layout;

    QWidget *top_block;
    QWidget *find_place;

    QWidget *bottom_block;
    QGridLayout *bottom_block_layout;
    QLabel *file_area_name;
    QGroupBox *button_group;
    QStackedWidget *stacked_widget_file_out;
    QGridLayout *stacked_widget_file_layout;
    QScrollArea *scroll_area_file;


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

#endif //DESCTOP_NORM_FILE_PAGE_H
