#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <vector>
#include <iostream>

#include <QPixmap>
#include <QImage>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

enum ACTION { NONE, CROP, ZOOM_IN, ZOOM_OUT, DRAW, SCALE, PICK };

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

 public:
    QImage Mat2QImage(cv::Mat const& src);
    cv::Mat QImage2Mat(QImage const& src);
    
    static Image* instance(std::string path = "");

    void center_circle(void);

    // Basic manipulation of the image. OpenCV.
    void crop(int,int,int,int);
    void invert_colors(void);
    void invert_image(void);
    void pick(int,int);
    void scale(int, int);
    void faces();
    void draw(int, int);

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
