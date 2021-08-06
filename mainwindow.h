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
#include "reg_page.h"
#include "home_page.h"
#include "customshadoweffect.h"
#include "round_graph.h"


class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private:
    QStackedWidget *stacked_widget;

    QTimer *timer;
    InPage *in_page;
    RegPage *reg_page;
    HomePage *home_page;
    fux::RoundGraph *rg;
    fux::RoundGraph *rg_;
    int i = 0;

private slots:
    void on_but_clicked();

protected slots:
    virtual void resizeEvent(QResizeEvent *event);
    void onTimeout();

};


#endif //DESCTOP_NORM_MAINWINDOW_H
