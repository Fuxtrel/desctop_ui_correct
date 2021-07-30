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
    QWidget* getLinkBgRegPage();
private:
    QWidget *bg_reg_page;
    QWidget *reg_page;
    QGridLayout *reg_layout;
};

#endif //DESCTOP_NORM_REG_PAGE_H
