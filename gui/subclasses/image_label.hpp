#include <iostream>
#include <QLabel>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QRubberBand>
#include <QPoint>
#include <memory>

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
    std::unique_ptr<QRubberBand> _rubberBandScale;
    std::unique_ptr<QRubberBand> _rubberBandCrop;

    QPoint _origin;
};

