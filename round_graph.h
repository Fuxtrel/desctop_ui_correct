#ifndef UNTITLED1_ROUND_GRAPH_H
#define UNTITLED1_ROUND_GRAPH_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QMainWindow>
#include <QLabel>


namespace fux {
    class RoundGraph : public QGraphicsView {

    Q_OBJECT

    public:

        RoundGraph(const double rectangle_x, const double rectangle_y, const double diameter, const double wid, QBrush color, QBrush bg_color,  QWidget *parent);

        ~RoundGraph() = default;

        void setColor(QBrush color);

        double getAngle();

        void setLoadPercent(int percent);

        void setBgColor(QBrush bg_color);

        QGraphicsView *view;

        QLabel *display_place;

    protected slots:

        void onTimeout();

    private:
        int angle;
        int start_angle;
        int delta_angle;
        const double width;
        const double size_in;
        const double diameter;
        const double rectangle_x;
        const double rectangle_y;
        const double rectangle_in_x;
        const double rectangle_in_y;
        double rectangle_small_x;
        double rectangle_small_y;
        QGraphicsEllipseItem *bg;
        QGraphicsEllipseItem *circle;
        QGraphicsEllipseItem *circle_in;
        QGraphicsEllipseItem *circle_end;
        QGraphicsEllipseItem *circle_begin;
        QBrush color;
        QTimer *timer;
        QWidget *parent;
        QGraphicsScene *scene;
        void setAngle(int angle);

    };
}

#endif //UNTITLED1_ROUND_GRAPH_H
