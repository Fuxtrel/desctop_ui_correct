#ifndef DESCTOP_NORM_FILE_PAGE_H
#define DESCTOP_NORM_FILE_PAGE_H

#include <QObject>
#include <QStackedWidget>

class FilePage : public QObject {
    Q_OBJECT
public:
    FilePage(QWidget *parent = nullptr, QStackedWidget *stacked_widget = nullptr);
    ~FilePage() = default;
private:
    QStackedWidget *stacked_widget;

};

#endif //DESCTOP_NORM_FILE_PAGE_H
