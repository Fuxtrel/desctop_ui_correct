#ifndef DESCTOP_NORM_REG_PAGE_H
#define DESCTOP_NORM_REG_PAGE_H

#include <QPushButton>
#include <QGridLayout>
#include <QResizeEvent>
#include <QLabel>
#include <QtSvg/QtSvg>

class RegPage {

public:
    RegPage(QWidget *parent = nullptr);
    ~RegPage() = default;
    QWidget* getLinkBgInPage();
private:
    QWidget *bg_in_page;
    QWidget *in_page;
    QGridLayout *in_layout;
};

#endif //DESCTOP_NORM_REG_PAGE_H
