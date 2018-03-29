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

void Image::scale(int origin_x, int origin_y, int final_x, int final_y)
{

}

void Image::crop(int x, int y, int width, int height)
{
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
    cv::flip(_modified, _modified, 1);
}

void Image::invert_colors(void)
{
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




