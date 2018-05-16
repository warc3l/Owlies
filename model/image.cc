#include "image.hpp"

Image* Image::_instance = 0;
Image* Image::instance(std::string path)
{
   if (_instance == 0)
        _instance = new Image;

    if (!path.empty())
    {
        _instance->set_modified_path_image(path);
        _instance->set_original_path_image(path);
        _instance->set_actual_action(NONE);
    }

    return _instance;
}

void Image::save_state()
{
    _saved_states.push(_modified.clone());
}

void Image::load_saved_state(void)
{
    if (!_saved_states.empty())
    {
        _modified = _saved_states.top();
        _saved_states.pop();
    }
}

void Image::draw(int x, int y)
{
    save_state();
    QSettings settings(_file_settings, QSettings::NativeFormat);

    int draw_size = settings.value("draw_settings_size", 10).toInt();
    int r_color = settings.value("draw_settings_r_color", 0).toInt();
    int g_color = settings.value("draw_settings_g_color", 0).toInt();
    int b_color = settings.value("draw_settings_b_color", 0).toInt();
    FORM form = static_cast<FORM>(settings.value("draw_settings_form", 0).toInt());
    // How to draw the triangle, rectangle and circle? 

    cv::Point2i center(x, y);
    
    if (form == CIRCLE)
        cv::circle(_modified, center, draw_size, cv::Scalar(b_color, g_color, r_color), CV_FILLED);
    else if (form == TRIANGLE)
    {
        std::vector<cv::Point> points {cv::Point(x - draw_size/2, y - draw_size*sqrt(3)/6), cv::Point(x + draw_size/2, y - draw_size*sqrt(3)/6), cv::Point(x, y + draw_size * sqrt(3)/3)};
        cv::fillConvexPoly(_modified, points, cv::Scalar(b_color, g_color, r_color));
    }
}

void Image::scale(int width, int height)
{
    save_state();

    cv::resize(_modified, _modified, cv::Size(width, height));
}

void Image::faces(void)
{
    save_state();

    cv::CascadeClassifier cascade("resources/data/haarcascade_frontalface_alt.xml");
    std::vector<cv::Rect> faces;
    cv::Mat gray;

    cv::cvtColor( _modified, gray, cv::COLOR_BGR2GRAY ); // Convert to Gray Scale
 
    // Resize the Grayscale Image  -> why you need to resize it?
 //   cv::resize( gray, smallImg, cv::Size(), fx, fx, cv::INTER_LINEAR ); 
 //   cv::equalizeHist( smallImg, smallImg );
 
    // Detect faces of different sizes using cascade classifier  -> it was changed from smallImg -> gray
    cascade.detectMultiScale( gray, faces, 1.1, 2, 0|cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30) );
    for (auto face: faces)
    {
        cv::rectangle(_modified, 
            cvPoint(cvRound(face.x), 
            cvRound(face.y)), 
            cvPoint(cvRound((face.x + face.width-1)), 
            cvRound((face.y + face.height-1))), 
            cv::Scalar(255, 0, 0), 3, 8, 0);
    }
}

void Image::thin(void)
{
    save_state();

    cv::Mat skel(_modified.size(), CV_8UC1, cv::Scalar(0));
    cv::Mat element = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(5, 5));
    cv::Mat dilated, eroded, substracted;

    cv::threshold(_modified, _modified, 10, 1, cv::THRESH_BINARY); 
    cv::cvtColor(_modified, _modified, cv::COLOR_BGR2GRAY); // 1-channel

    do
    {
        cv::erode(_modified, eroded, element);
        cv::dilate(eroded, dilated, element);
        cv::subtract(_modified, dilated, substracted);
        cv::bitwise_or(skel, substracted, skel);
        _modified = eroded.clone();
    } while (cv::countNonZero(_modified) != 0);

    cv::threshold(skel, skel, 0.5, 255, CV_THRESH_BINARY);
    cv::cvtColor(skel, _modified, cv::COLOR_GRAY2BGR); // 3-channel
}

void Image::sature(void)
{
    save_state();

    cv::Mat dst;
    cv::inRange(_modified, cv::Scalar(0, 80, 100), cv::Scalar(255, 255, 255), dst); // Return 1-channel
    
    cv::cvtColor(dst, dst, CV_GRAY2BGR, 3); // Transform it to 3-channel
    cv::bitwise_and(_modified, dst, _modified);
}

void Image::blur_filter(void)
{
    save_state();

    cv::blur(_modified, _modified, cv::Size(5, 5));
}

void Image::bilateral_filter(void)
{
    save_state();

    cv::Mat dst;
    cv::bilateralFilter(_modified, dst, 15, 80, 80);
    _modified = dst;
}

void Image::laplacian_filter(void)
{
    save_state();

    cv::Laplacian(_modified, _modified, CV_8U);
}

void Image::box_filter(void)
{
    save_state();

    cv::boxFilter(_modified, _modified, CV_8U, cv::Size(3,3));
}

void Image::gaussian_filter(void)
{
    save_state();

    cv::GaussianBlur(_modified, _modified, cv::Size(3,3), 1.0);    
}

void Image::scharr_filter(void)
{
    save_state();

    cv::Scharr(_modified, _modified, CV_8U, 0, 1);
}

void Image::median_filter(void)
{
    save_state();

    cv::medianBlur(_modified, _modified, 5);
}

void Image::sobel_filter(void)
{
    save_state();

    cv::Sobel(_modified, _modified, CV_8U, 1, 0);
}

void Image::erode(void)
{
    save_state();

    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::erode(_modified, _modified, element);
}

void Image::dilate(void)
{
    save_state();

    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::dilate(_modified, _modified, element);
}

void Image::opening(void)
{
    save_state();

    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3));
    cv::Mat dst;
    cv::erode(_modified, dst, element);
    cv::dilate(dst, _modified, element);
}

void Image::closing(void)
{
    save_state();

    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3));
    cv::Mat dst;
    cv::dilate(_modified, dst, element);
    cv::erode(dst, _modified, element);
}

void Image::crop(int x, int y, int width, int height)
{
    save_state();

    if (x < 0)
    {
        width = width + x;
        x = 0;
    }

    if (y < 0)
    {
        height = height + y;
        y = 0;
    }

    width = (width + x < _modified.cols)? width : abs(_modified.cols - x);
    height = (height + y < _modified.rows)? height: abs(_modified.rows - y);

    cv::Rect crop_rect(x, y, width, height);
    _modified = _modified(crop_rect);
}

void Image::invert_image(void)
{
    save_state();

    cv::flip(_modified, _modified, 1);
}

void Image::invert_colors(void)
{
    save_state();

    cv::bitwise_not(_modified, _modified);
}

void Image::pick(int x, int y)
{
    cv::Point3_<uchar>* point = _modified.ptr<cv::Point3_<uchar> >(y, x);     
    std::cout << "(" << int(point->z) << "," << int(point->y) << "," << int(point->x) << ")" << std::endl;
}

QPixmap Image::get_modified_pixmap()
{
    QImage qimg = Mat2QImage(_modified);
    return QPixmap::fromImage(qimg);
}

QPixmap Image::get_original_pixmap()
{
    QImage qimg = Mat2QImage(_original);
    return QPixmap::fromImage(qimg);
}

QImage Image::Mat2QImage(cv::Mat const& src)
{
    cv::Mat temp; // make the same cv::Mat
    cv::cvtColor(src, temp, CV_BGR2RGB); // cvtColor Makes a copt, that what i need
    QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    dest.bits(); // enforce deep copy, see documentation 
    return dest;
}

cv::Mat Image::QImage2Mat(QImage const& src)
{
    cv::Mat tmp(src.height(),src.width(),CV_8UC3,(uchar*)src.bits(),src.bytesPerLine());
    cv::Mat result; // deep copy just in case (my lack of knowledge with open cv)
    cv::cvtColor(tmp, result, CV_BGR2RGB);
    return result;
}




