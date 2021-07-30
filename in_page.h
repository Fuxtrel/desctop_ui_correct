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
private:
    QWidget *bg_in_page;
    QWidget *in_page;
    QGridLayout *in_layout;
};


#endif //DESCTOP_NORM_IN_PAGE_H
