#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1920, 1080);
    w.setWindowTitle("UpStorage");
    w.show();
    return QApplication::exec();
}
