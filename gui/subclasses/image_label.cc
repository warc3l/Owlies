#include "image_label.hpp"

ImageLabel::ImageLabel(QWidget* parent)
{
    _rubberBand = nullptr;
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
                if (!_rubberBand)
                    _rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
                _rubberBand->setGeometry(QRect(_origin, QSize()));
                _rubberBand->show();
                break;
            case PICK:
                img->pick(_origin.x(), _origin.y());
                break;
        }
    }
}

void ImageLabel::mouseMoveEvent(QMouseEvent* event)
{
    if (_rubberBand)
        _rubberBand->setGeometry(QRect(_origin, event->pos()).normalized());
}

void ImageLabel::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        Image* img = Image::instance();
        switch (img->get_actual_action())
        {
            case NONE:
                break;
            case CROP:
                _rubberBand->hide();

                int pos_x = _rubberBand->geometry().x();
                int pos_y = _rubberBand->geometry().y();
                int width = _rubberBand->geometry().width();
                int height = _rubberBand->geometry().height();

                img->crop(pos_x, pos_y, width, height);
                setPixmap(img->get_modified_pixmap());
                break;
        }
    }
}
