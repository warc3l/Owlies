#ifndef _IMAGE_LABEL_HPP
#define _IMAGE_LABEL_HPP

#include <iostream>
#include <QLabel>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QRubberBand>
#include <QPoint>
#include <QStatusBar>
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

 private:
    bool _mouseMoving;

    std::unique_ptr<QRubberBand> _rubberBandScale;
    std::unique_ptr<QRubberBand> _rubberBandCrop;
    QPixmap _pixmap;
    QPoint _origin;

    QWidget* _parent;
};

#endif
