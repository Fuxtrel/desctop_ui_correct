#include "round_graph.h"

fux::RoundGraph::RoundGraph(const double rectangle_x, const double rectangle_y, const double diameter,
                            const double width, QBrush color, QBrush bg_color, QWidget *parent) :
                            rectangle_x(rectangle_x), rectangle_y(rectangle_y), diameter(diameter), width(width), color(color),
                            parent(parent), scene(new QGraphicsScene(rectangle_x, rectangle_y, diameter, diameter, parent)),
                            size_in(diameter - (2 * width)), rectangle_in_x(width),
                            rectangle_in_y(width) {
    rectangle_small_x = (diameter / 2) - (width / 2);
    rectangle_small_y = 0;
    view = new QGraphicsView(parent);
    scene = new QGraphicsScene(0, 0, diameter, diameter, view);
    view->setGeometry(rectangle_x, rectangle_y, diameter, diameter);
    view->setRenderHint(QPainter::Antialiasing);
    view->setScene(scene);
    bg = new QGraphicsEllipseItem(0, 0, diameter, diameter);
    circle = new QGraphicsEllipseItem(0, 0, diameter, diameter);
    circle_in = new QGraphicsEllipseItem(rectangle_in_x, rectangle_in_y, size_in, size_in);
    circle_end = new QGraphicsEllipseItem(rectangle_small_x, rectangle_small_y, width, width);
    circle_begin = new QGraphicsEllipseItem(rectangle_small_x, rectangle_small_y, width, width);
    angle = 0;
    start_angle = 0;
    delta_angle = 16;
    circle_end->setTransformOriginPoint((diameter / 2), (diameter / 2));
    circle->setTransformOriginPoint(rectangle_x + (diameter / 2), rectangle_y + (diameter / 2));
    circle->setStartAngle(90 * 16);
    circle->setSpanAngle(0);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    bg->setPen(Qt::NoPen);
    circle->setPen(Qt::NoPen);
    circle_in->setPen(Qt::NoPen);
    circle_end->setPen(Qt::NoPen);
    circle_begin->setPen(Qt::NoPen);
    bg->setBrush(QColor::fromRgb(247, 249, 251));
    circle->setBrush(color);
    circle_in->setBrush(bg_color);
    circle_end->setBrush(color);
    circle_begin->setBrush(color);
    view->setBackgroundBrush(bg_color);

    scene->addItem(bg);
    scene->addItem(circle);
    scene->addItem(circle_in);
    scene->addItem(circle_end);
    scene->addItem(circle_begin);
    view->setFrameShape(QFrame::NoFrame);
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &RoundGraph::onTimeout);

    display_place = new QLabel(parent);
    display_place->setGeometry(rectangle_x + (diameter / 2) - 30, rectangle_y + (diameter / 2) - 10, 60, 20);
    display_place->setText(QString::number(getAngle() / 3.6) + " %");
    display_place->setAlignment(Qt::AlignCenter);
    display_place->setStyleSheet("border:0px;background-color:rgba(0, 0, 0, 0);");

}

void fux::RoundGraph::setAngle(int grad) {
    angle = grad * 16;
}

void fux::RoundGraph::setColor(QBrush color) {
    circle->setBrush(color);
    circle_end->setBrush(color);
    circle_begin->setBrush(color);
}

void fux::RoundGraph::setBgColor(QBrush bg_color) {
    circle_in->setBrush(bg_color);
    view->setBackgroundBrush(bg_color);
}

double fux::RoundGraph::getAngle() {
    return angle / 16;
}

void fux::RoundGraph::setLoadPercent(int percent) {
//    if(angle == 0){
//        circle_end->hide();
//        circle_begin->hide();
//        circle->hide();
//    }else {
//        circle_end->show();
//        circle_begin->show();
//        circle->show();
//    }
    setAngle(percent * 3.6);
    circle->setSpanAngle(-angle);
    timer->start(15);
    circle_end->setRotation((angle / 16) - 1);
}

void fux::RoundGraph::onTimeout() {
    start_angle -= delta_angle;
    display_place->setText(QString::number(-int(start_angle / 16 / 3.6)) + " %");
    circle_end->setRotation(-start_angle / 16 -1);
    circle->setSpanAngle(start_angle);
    if(start_angle <= -angle){
        timer->stop();
    }
};
