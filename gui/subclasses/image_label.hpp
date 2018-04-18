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
    virtual void setPixmap(const QPixmap& pixmap);

 protected:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void paintEvent(QPaintEvent* event);

 private:
    std::unique_ptr<QRubberBand> _rubberBandScale;
    std::unique_ptr<QRubberBand> _rubberBandCrop;
    QPixmap _pixmap;

    QPoint _origin;
    int _coord_x;
    int _coord_y;
};

