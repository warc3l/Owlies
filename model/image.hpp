#ifndef _IMAGE_HPP
#define _IMAGE_HPP

#include <string>
#include <vector>
#include <iostream>

#include <QPixmap>
#include <QImage>
#include <QSettings>

#include <stack>
#include <opencv2/dnn.hpp>
#include <opencv2/dnn/shape_utils.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect.hpp>

#include <boost/lexical_cast.hpp>

enum FORM { CIRCLE, TRIANGLE };
enum ACTION { NONE, CROP, DRAW, SCALE, PICK };

class Image
{
 private:
    Image() {};

    static Image* _instance;

    std::string _path_original_image {0};
    std::string _path_modified_image {0};

    cv::Mat _original;
    cv::Mat _modified;

    ACTION _actual_action; 

    std::stack<cv::Mat> _saved_states;
    const QString _file_settings = "settings.ini";

 public:
    QImage Mat2QImage(cv::Mat const& src);
    cv::Mat QImage2Mat(QImage const& src);
    
    static Image* instance(std::string path = "");

    // Undo functionality
    void save_state(void);
    void load_saved_state(void);

    // Basic manipulation of the image. OpenCV.
    void crop(int,int,int,int);
    void invert_colors(void);
    void invert_image(void);
    cv::Point3_<uchar>* pick(int,int);
    void scale(int, int);
    void faces();
    void recognize();
    void zoom_in(void);
    void zoom_out(void);
    void draw(int, int);
    void sature(void);
    void thin(void);

    // Filters
    void blur_filter(void);
    void bilateral_filter(void);
    void laplacian_filter(void);
    void gaussian_filter(void);
    void scharr_filter(void);
    void box_filter(void);
    void median_filter(void);
    void sobel_filter(void);

    // Morphological transformations
    void erode(void);
    void dilate(void);
    void opening(void);
    void closing(void);

    // Representation of that image.
    QPixmap get_modified_pixmap(void);  
    QPixmap get_original_pixmap(void);

    void set_original_path_image(std::string path) { _original = cv::imread(path.c_str(), cv::IMREAD_COLOR); _path_original_image = path; }
    void set_modified_path_image(std::string path) { _modified = cv::imread(path.c_str(), cv::IMREAD_COLOR); _path_modified_image = path; }

    std::string get_original_path_image(void) { return _path_original_image; }
    std::string get_modified_path_image(void) { return _path_modified_image; }

    void set_actual_action(ACTION par) { _actual_action = par; }
    ACTION get_actual_action(void) { return _actual_action; } 

};

#endif
