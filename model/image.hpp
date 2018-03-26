#include <string>
#include <QPixmap>
#include <QImage>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


class Image
{
 private:
    Image() {};

    static Image* _instance;

    std::string _path_original_image {0};
    std::string _path_modified_image {0};

    cv::Mat _original;
    cv::Mat _modified;

 public:
    QImage Mat2QImage(cv::Mat const& src);
    cv::Mat QImage2Mat(QImage const& src);
    
    static Image* instance(std::string path = "");

    // Basic manipulation of the image. OpenCV.
    void reescale(void);
    void change_color(void);

    // Representation of that image.
    QPixmap get_modified_pixmap(void);  

    void set_original_path_image(std::string path) { _original = cv::imread(path.c_str(), cv::IMREAD_COLOR); _path_original_image = path; }
    void set_modified_path_image(std::string path) { _modified = cv::imread(path.c_str(), cv::IMREAD_COLOR); _path_modified_image = path; }

    std::string get_original_path_image(void) { return _path_original_image; }
    std::string get_modified_path_image(void) { return _path_modified_image; }

};

