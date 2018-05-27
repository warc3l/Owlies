#include "image_label.hpp"

ImageLabel::ImageLabel(QWidget* parent)
{
    _rubberBandCrop = nullptr;
    _rubberBandScale = nullptr;
    _mouseMoving = false;
    _parent = parent;

    setMouseTracking(true);
}

void ImageLabel::setPixmap(const QPixmap& pixmap)
{
    _pixmap = pixmap;
    QLabel::setPixmap(pixmap);
}

void ImageLabel::mousePressEvent(QMouseEvent* event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        Image* img = Image::instance();
        _origin = event->pos();

        _mouseMoving = true;

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
                std::cout << "ZOOM IN AT: " << _origin.x() << " and " << _origin.y() << std::endl;

                img->zoom_in(_origin.x(), _origin.y());
                setPixmap(img->get_modified_pixmap());
                break;
        }
    }
}

void ImageLabel::mouseMoveEvent(QMouseEvent* event)
{
    Image* img = Image::instance();

    if (_rubberBandCrop && img->get_actual_action() == CROP )
        _rubberBandCrop->setGeometry(QRect(_origin, event->pos()).normalized());

    QStatusBar* statusbar = _parent->parentWidget()->parentWidget()->parentWidget()->findChild<QStatusBar*>("statusbar");

    if ( _rubberBandScale && _rubberBandScale->isVisible() && img->get_actual_action() == SCALE)
    {
        _rubberBandScale->setGeometry(QRect(_origin, mapToGlobal(event->pos())).normalized());
        std::string new_size = "(" + std::to_string(_rubberBandScale->geometry().width()) + ", " + std::to_string(_rubberBandScale->geometry().height()) + ")";
        statusbar->findChild<QLabel*>("lbl_image_size")->setText(QString::fromStdString(new_size));        
    }

    if ( _mouseMoving && img->get_actual_action() == DRAW)
    {
        img->draw(event->pos().x(), event->pos().y());
        setPixmap(img->get_modified_pixmap());
    }

    std::string cursor_position = "(" + std::to_string(event->pos().x()) + ", " + std::to_string(event->pos().y()) + ")"; 
    QLabel* lbl_image_pointer = statusbar->findChild<QLabel*>("lbl_image_pointer");
    if (lbl_image_pointer != 0)
        lbl_image_pointer->setText(QString::fromStdString(cursor_position));
}

void ImageLabel::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        Image* img = Image::instance();
        int width, height;
        
        _mouseMoving = false;

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

                QStatusBar* statusbar = _parent->parentWidget()->parentWidget()->parentWidget()->findChild<QStatusBar*>("statusbar");
                std::string new_size = "(" + std::to_string(width) + ", " + std::to_string(height) + ")";
                statusbar->findChild<QLabel*>("lbl_image_size")->setText(QString::fromStdString(new_size));        
                break;
        }
    }
}
