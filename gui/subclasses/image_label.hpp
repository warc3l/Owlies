#include <iostream>
#include <QLabel>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QRubberBand>
#include <QPoint>

#include "../../model/image.hpp"

class ImageLabel : public QLabel
{
 public:
    ImageLabel(QWidget* parent);

 protected:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
 private:
    QRubberBand* _rubberBand;
    QPoint _origin;
};

