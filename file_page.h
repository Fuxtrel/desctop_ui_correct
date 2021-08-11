#ifndef DESCTOP_NORM_FILE_PAGE_H
#define DESCTOP_NORM_FILE_PAGE_H

#include <QObject>
#include <QStackedWidget>
#include <QGridLayout>
#include <QScrollArea>

class FilePage : public QObject {
    Q_OBJECT
public:
    FilePage(QWidget *parent = nullptr, QStackedWidget *stacked_widget = nullptr);
    ~FilePage() = default;
    QWidget *bg_file_page;
private:
    QStackedWidget *stacked_widget;
    QScrollArea *scroll_area_file;
    QWidget *left_buttons_block;
    QGridLayout *layout;
    QStackedWidget *stacked_widget_file_out;
    QGridLayout *stacked_widget_file_layout;

};

#endif //DESCTOP_NORM_FILE_PAGE_H
