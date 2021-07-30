#ifndef DESCTOP_NORM_MAINWINDOW_H
#define DESCTOP_NORM_MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QDebug>
#include <QTimer>
#include <QPushButton>
#include <QGridLayout>
#include <QResizeEvent>
#include <QLabel>
#include <QtSvg/QtSvg>
#include "in_page.h"


class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private:
    QStackedWidget *stacked_widget;

    QWidget *bg_reg_page;
//    QWidget *bg_in_page;
    QWidget *bg_home_page;

    QWidget *reg_page;
//    QWidget *in_page;
    QWidget *home_page;

    QTimer *timer;
    QGridLayout *reg_layout;
    QGridLayout *home_layout;

    QLabel *left_title_in_page;
    QLabel *right_title_in_page;
    QLabel *right_subtitle_in_page;

    QSvgWidget *left_circle_title_in_page;
    QSvgWidget *left_separator_in_page;
    QPushButton *check_box_in_page;

    InPage *in_page;

private slots:
    void on_but_clicked();

protected slots:
    virtual void resizeEvent(QResizeEvent *event);
    void onTimeout();

};


#endif //DESCTOP_NORM_MAINWINDOW_H
