#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1920, 1080);
    w.setBaseSize(1280, 780);
    w.setMinimumSize(1280, 780);
    w.setWindowTitle("UpStorage");
    w.show();
    return QApplication::exec();
}
