#include "image_label.hpp"

ImageLabel::ImageLabel(QWidget* parent)
{
    _rubberBandCrop = nullptr;
    _rubberBandScale = nullptr;
    _coord_x = -1;
    _coord_y = -1;
}

void ImageLabel::setPixmap(const QPixmap& pixmap)
{
    _pixmap = pixmap;
    QLabel::setPixmap(pixmap);
}

void ImageLabel::paintEvent(QPaintEvent* paint)
{
    Image* img = Image::instance();
    if (img->get_actual_action() == ZOOM_IN && _coord_x != -1) 
    {
        int width = _pixmap.width();
        int height = _pixmap.height();

        std::cout << "New paint! zoom in on " << _coord_x << " and " << _coord_y << std::endl;

        QPainter painter(this);
//        painter.translate(width/2, height/2);
//        painter.scale(2,2);
        painter.translate(width/2 -_coord_x, height/2 -_coord_y);
        painter.drawPixmap(0, 0, _pixmap);
        _coord_x = -1;
        _coord_y = -1;
    }
    else if (img->get_actual_action() == ZOOM_OUT && _coord_x != -1)
    {
        QPainter painter(this);
        painter.scale(0.5, 0.5);
        painter.drawPixmap(0, 0, _pixmap);
    }
    else
    {
        QLabel::paintEvent(paint);
    }
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
            case ZOOM_IN:
                std::cout << "Hello, world " << std::endl;
                _coord_x = _origin.x();
                _coord_y = _origin.y();
                update();
                /*
                _coord_x = -1;
                _coord_y = -1;
                */
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
