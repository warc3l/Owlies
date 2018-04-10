#include "image_label.hpp"

ImageLabel::ImageLabel(QWidget* parent)
{
    _rubberBandCrop = nullptr;
    _rubberBandScale = nullptr;
}

void ImageLabel::mousePressEvent(QMouseEvent* event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        Image* img = Image::instance();
        _origin = event->pos();

        switch(img->get_actual_action())
        {
            case NONE:
                break;                
            case CROP:
                if (!_rubberBandCrop)
                    _rubberBandCrop = std::make_unique<QRubberBand>(QRubberBand::Rectangle, this);
                _rubberBandCrop->setGeometry(QRect(_origin, QSize()));
                _rubberBandCrop->show();
                break;
            case PICK:
                img->pick(_origin.x(), _origin.y());
                break;
            case DRAW:
                img->draw(_origin.x(), _origin.y());
                setPixmap(img->get_modified_pixmap());
                break;
            case SCALE:
                if (!_rubberBandScale)
                    _rubberBandScale = std::make_unique<QRubberBand>(QRubberBand::Rectangle);
                _origin = mapToGlobal(QPoint(0,0));
                _rubberBandScale->setGeometry(QRect(_origin, mapToGlobal(event->pos())).normalized());
                _rubberBandScale->show();
                break;
        }
    }
}

void ImageLabel::mouseMoveEvent(QMouseEvent* event)
{
    Image* img = Image::instance();

    if (_rubberBandCrop && img->get_actual_action() == CROP )
        _rubberBandCrop->setGeometry(QRect(_origin, event->pos()).normalized());

    if ( _rubberBandScale && img->get_actual_action() == SCALE)
        _rubberBandScale->setGeometry(QRect(_origin, mapToGlobal(event->pos())).normalized());

    if (img->get_actual_action() == DRAW)
    {
        img->draw(event->pos().x(), event->pos().y());
        setPixmap(img->get_modified_pixmap());
    }
}

void ImageLabel::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        Image* img = Image::instance();
        int width, height;

        switch (img->get_actual_action())
        {
            case NONE:
                break;
            case SCALE:
                _rubberBandScale->hide();
                width = _rubberBandScale->geometry().width();
                height = _rubberBandScale->geometry().height();
                img->scale(width, height);
                setPixmap(img->get_modified_pixmap());
                break;
            case CROP:
                _rubberBandCrop->hide();
                int pos_x = _rubberBandCrop->geometry().x();
                int pos_y = _rubberBandCrop->geometry().y();
                width = _rubberBandCrop->geometry().width();
                height = _rubberBandCrop->geometry().height();

                img->crop(pos_x, pos_y, width, height);
                setPixmap(img->get_modified_pixmap());
                break;
        }
    }
}
