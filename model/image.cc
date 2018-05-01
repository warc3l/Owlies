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

void Image::draw(int x, int y)
{
    cv::Point2i center(x, y);

    cv::circle(_modified, center, 10, cv::Scalar(0, 0, 0), CV_FILLED);
}

void Image::scale(int width, int height)
{
    cv::resize(_modified, _modified, cv::Size(width, height));
}

void Image::faces(void)
{
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

void Image::blur_filter(void)
{
    cv::blur(_modified, _modified, cv::Size(5, 5));
}

void Image::bilateral_filter(void)
{
    cv::Mat dst;
    cv::bilateralFilter(_modified, dst, 15, 80, 80);
    _modified = dst;
}

void Image::laplacian_filter(void)
{
    cv::Laplacian(_modified, _modified, CV_8U);
}

void Image::box_filter(void)
{
    cv::boxFilter(_modified, _modified, CV_8U, cv::Size(3,3));
}

void Image::gaussian_filter(void)
{
    cv::GaussianBlur(_modified, _modified, cv::Size(3,3), 1.0);    
}

void Image::scharr_filter(void)
{
    cv::Scharr(_modified, _modified, CV_8U, 0, 1);
}

void Image::median_filter(void)
{
    cv::medianBlur(_modified, _modified, 5);
}

void Image::sobel_filter(void)
{
    cv::Sobel(_modified, _modified, CV_8U, 1, 0);
}

void Image::erode(void)
{
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::erode(_modified, _modified, element);
}

void Image::dilate(void)
{
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::dilate(_modified, _modified, element);
}

void Image::opening(void)
{
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3));
    cv::Mat dst;
    cv::erode(_modified, dst, element);
    cv::dilate(dst, _modified, element);
}

void Image::closing(void)
{
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3));
    cv::Mat dst;
    cv::dilate(_modified, dst, element);
    cv::erode(dst, _modified, element);
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




