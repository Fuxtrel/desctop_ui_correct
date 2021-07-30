#ifndef DESCTOP_NORM_HOME_PAGE_H
#define DESCTOP_NORM_HOME_PAGE_H

#include <QPushButton>
#include <QGridLayout>
#include <QResizeEvent>
#include <QLabel>
#include <QtSvg/QtSvg>

class HomePage {
public:
    HomePage(QWidget *parent = nullptr);
    ~HomePage() = default;
    QWidget* getLinkBgHomePage();
private:
    QWidget *bg_home_page;
    QWidget *home_page;
    QGridLayout *home_layout;
};


#endif //DESCTOP_NORM_HOME_PAGE_H
