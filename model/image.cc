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

void Image::zoom_in()
{
    save_state();
    cv::pyrUp(_modified, _modified, cv::Size( _modified.cols*2, _modified.rows*2 ));
}

void Image::zoom_out()
{
    save_state();
    cv::pyrDown(_modified, _modified, cv::Size( _modified.cols/2, _modified.rows/2 ));
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
    QSettings settings(_file_settings, QSettings::NativeFormat);

    cv::cvtColor( _modified, gray, cv::COLOR_BGR2GRAY ); // Convert to Gray Scale
    
    double scale = settings.value("faces_settings_scale", 1.1).toDouble();
    int neighbours = settings.value("faces_settings_neighbours", 3).toInt();

    int r_color = settings.value("faces_settings_r_color", 0).toInt();
    int g_color = settings.value("faces_settings_g_color", 0).toInt();
    int b_color = settings.value("faces_settings_b_color", 0).toInt();

    cascade.detectMultiScale(gray, faces, scale, neighbours, 0|cv::CASCADE_SCALE_IMAGE);
    for (auto face: faces)
    {
        cv::rectangle(_modified, 
            cvPoint(cvRound(face.x), 
            cvRound(face.y)), 
            cvPoint(cvRound((face.x + face.width-1)), 
            cvRound((face.y + face.height-1))), 
            cv::Scalar(b_color, g_color, r_color), 3, 8, 0);
    }
}

std::vector<std::string> createClaseNames() {
    std::vector<std::string> classNames;
    classNames.push_back("background");
    classNames.push_back("aeroplane");
    classNames.push_back("bicycle");
    classNames.push_back("bird");
    classNames.push_back("boat");
    classNames.push_back("bottle");
    classNames.push_back("bus");
    classNames.push_back("car");
    classNames.push_back("cat");
    classNames.push_back("chair");
    classNames.push_back("cow");
    classNames.push_back("diningtable");
    classNames.push_back("dog");
    classNames.push_back("horse");
    classNames.push_back("motorbike");
    classNames.push_back("person");
    classNames.push_back("pottedplant");
    classNames.push_back("sheep");
    classNames.push_back("sofa");
    classNames.push_back("train");
    classNames.push_back("tvmonitor");
    return classNames;
}   

void Image::recognize(void)
{
    // https://hackaday.com/2018/05/23/using-tensorflow-to-recognize-your-own-objects/    
    // Python Binding??
    std::cout << "Lets recognize!!!" << std::endl;
    auto cvNet = cv::dnn::readNetFromCaffe("input/MobileNetSSD_deploy.prototxt", "input/MobileNetSSD_deploy.caffemodel"); //, "../models/ssd_mobilenet_v1_coco_2017_11_17/ssd_mobilenet_v1_coco_2017_11_17.pbtxt", "rb");
    cv::Mat frame;

    std::cout << "cvNet created" << std::endl;
/*
    cvNet.setPreferableBackend(3); // DNN_BACKEND_OPENCV
    cvNet.setPreferableTarget(0); // CPU
*/

//    cv::resize(_modified, _modified, cv::Size(300, 300));
    auto size = cv::Size(300, 300);
    auto mean = 127.5;
    std::cout << "After resize. Before blob from image " << std::endl;
    cv::Mat blob = cv::dnn::blobFromImage(_modified, 0.007843, size, mean);
    std::cout << "Lets input a blob" << std::endl;
    cvNet.setInput(blob);
    std::cout << "lets forward!" << std::endl;
    cv::Mat out = cvNet.forward();
    std::cout << "Dims:  " << out.dims << std::endl;
    std::cout << "Size: " << out.size() << std::endl;
    
    std::cout << out.at<cv::Vec3f>(0,0,0)[0] << std::endl;
    std::vector<std::string> classNames = createClaseNames();

    for (int i=0; i < out.size[2]; i++) {

        // print information into console
        std::cout << "-----------------" << std::endl;
        std::cout << "Object nr. " << i + 1 << std::endl;

        // detected class
        int indxCls[4] = { 0, 0, i, 1 };
        int cls = out.at<float>(indxCls);
        std::cout << "class: " << classNames[cls] << std::endl;

        // confidence
        int indxCnf[4] = { 0, 0, i, 2 };
        float cnf = out.at<float>(indxCnf);
        std::cout << "confidence: " << cnf * 100 << "%" << std::endl;

        // bounding box
        int indxBx[4] = { 0, 0, i, 3 };
        int indxBy[4] = { 0, 0, i, 4 };
        int indxBw[4] = { 0, 0, i, 5 };
        int indxBh[4] = { 0, 0, i, 6 };
        int Bx = out.at<float>(indxBx) * _modified.size().width;
        int By = out.at<float>(indxBy) * _modified.size().height;
        int Bw = out.at<float>(indxBw) * _modified.size().width - Bx;
        int Bh = out.at<float>(indxBh) * _modified.size().height - By;
        std::cout << "bounding box [x, y, w, h]: " << Bx << ", " << By << ", " << Bw << ", " << Bh << std::endl;

        // draw bounding box to image
        cv::Rect bbox(Bx, By, Bw, Bh);
        rectangle(_modified, bbox, cv::Scalar(255,0,255),1,8,0);

    }
/*
    for(int i=0; i<out.at<cv::Vec3f>(0,0,0).rows; i++){
        std::cout << "HELLO: " << out.at<cv::Vec3f>(0,0,0)[i] << std::endl;
        int idx = out.at<cv::Vec3f>(0, 0, i)[1];
        std::cout << "IDX is " << idx << std::endl;

        int box = out.at<cv::Vec3f>(0, 0, i)
    }
*/

/*
	# loop over the detections
	for i in np.arange(0, detections.shape[2]):
		# extract the confidence (i.e., probability) associated with
		# the prediction
		confidence = detections[0, 0, i, 2]

		# filter out weak detections by ensuring the `confidence` is
		# greater than the minimum confidence
		if confidence > args["confidence"]:
			# extract the index of the class label from the
			# `detections`, then compute the (x, y)-coordinates of
			# the bounding box for the object
			idx = int(detections[0, 0, i, 1])
			box = detections[0, 0, i, 3:7] * np.array([w, h, w, h])
			(startX, startY, endX, endY) = box.astype("int")

			# draw the prediction on the frame
			label = "{}: {:.2f}%".format(CLASSES[idx],
				confidence * 100)
			detected_objects.append(label)
			cv2.rectangle(frame, (startX, startY), (endX, endY),
				COLORS[idx], 2)
			y = startY - 15 if startY - 15 > 15 else startY + 15
			cv2.putText(frame, label, (startX, y),
cv2.FONT_HERSHEY_SIMPLEX, 0.5, COLORS[idx], 2)  
*/  
    /*
    for (int i = 0; i< out.at<cv::Vec3d>(0, 0).size(); i++)
    {   
        std::cout << "lol" << std::endl;
        auto confidence = out[0][0][i][2];
        int idx = out[0,0,i,1];
        out.at

    }
    */
}

void Image::thin(void)
{
    save_state();

    QSettings settings(_file_settings, QSettings::NativeFormat);
    
    int shape = settings.value("thin_settings_shape", 1).toInt();
    int k_size = settings.value("thin_settings_k_size", 5).toInt();

    double pre_thresh = settings.value("thin_settings_pre_threshold_thresh", 0.5).toDouble();
    double pre_max_value = settings.value("thin_settings_pre_threshold_max_value", 10).toDouble();

    int max_intents = settings.value("thin_settings_max_intents").toInt();
    bool detect_branch_points = settings.value("thin_settings_detect_branch_points", false).toBool();

    double post_thresh = settings.value("thin_settings_post_threshold_thresh", 0.5).toDouble();
    double post_max_value = settings.value("thin_settings_post_threshold_max_value", 255).toDouble();
    
    cv::Mat skel(_modified.size(), CV_8UC1, cv::Scalar(0));
    cv::Mat element = cv::getStructuringElement(shape, cv::Size(k_size, k_size));
    cv::Mat dilated, eroded, substracted;

    cv::threshold(_modified, _modified, pre_thresh, pre_max_value, cv::THRESH_BINARY); 
    cv::cvtColor(_modified, _modified, cv::COLOR_BGR2GRAY); // 1-channel

    int i = 0;
    do
    {
        cv::erode(_modified, eroded, element);
        cv::dilate(eroded, dilated, element);
        cv::subtract(_modified, dilated, substracted);
        cv::bitwise_or(skel, substracted, skel);
        _modified = eroded.clone();
        i++;
    } while (cv::countNonZero(_modified) != 0 && i <= max_intents);

    if (detect_branch_points)
        std::cout << "NOT IMPLEMENTED. DETECTING BRANCH POINTS..." << std::endl;

    cv::threshold(skel, skel, post_thresh, post_max_value, CV_THRESH_BINARY);
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
    QSettings settings(_file_settings, QSettings::NativeFormat);

    int k_size = settings.value("blur_filter_settings_k_size", 5).toInt();

    cv::blur(_modified, _modified, cv::Size(k_size, k_size));
}

void Image::bilateral_filter(void)
{
    save_state();

    QSettings settings(_file_settings, QSettings::NativeFormat);

    int diameter = settings.value("bilateral_filter_settings_diameter", 15).toInt();
    double sigma_color = settings.value("bilateral_filter_settings_sigma_color", 80).toDouble();
    double sigma_space = settings.value("bilateral_filter_settings_sigma_space", 80).toDouble();

    cv::Mat dst;
    cv::bilateralFilter(_modified, dst, diameter, sigma_color, sigma_space);
    _modified = dst;
}

void Image::laplacian_filter(void)
{
    save_state();

    QSettings settings(_file_settings, QSettings::NativeFormat);

    int k_size = settings.value("laplacian_filter_settings_k_size", 3).toInt();
    int scale = settings.value("laplacian_filter_settings_scale", 1).toInt();
    int delta = settings.value("laplacian_filter_settings_delta", 1).toInt();

    cv::Laplacian(_modified, _modified, CV_8U, k_size, scale, delta);
}

void Image::box_filter(void)
{
    save_state();

    QSettings settings(_file_settings, QSettings::NativeFormat);

    int depth = settings.value("box_filter_settings_depth", 50).toInt();
    int k_size = settings.value("box_filter_settings_k_size", 3).toInt();
    bool normalized = settings.value("box_filter_settings_normalized", true).toBool();

    cv::boxFilter(_modified, _modified, depth, cv::Size(k_size,k_size), cv::Point(-1,-1), normalized);
}

void Image::gaussian_filter(void)
{
    save_state();

    QSettings settings(_file_settings, QSettings::NativeFormat);

    int k_size = settings.value("gaussian_filter_settings_k_size", 3).toInt();
    double sigma_x = settings.value("gaussian_filter_settings_sigma_x", 1.0).toDouble();
    double sigma_y = settings.value("gaussian_filter_settings_sigma_y", 0.0).toDouble();

    cv::GaussianBlur(_modified, _modified, cv::Size(k_size, k_size), sigma_x, sigma_y);    
}

void Image::scharr_filter(void)
{
    save_state();

    QSettings settings(_file_settings, QSettings::NativeFormat);

    int scale = settings.value("scharr_filter_settings_scale", 1).toInt();
    int delta = settings.value("scharr_filter_settings_delta", 0).toInt();
    int dx = settings.value("scharr_filter_settings_dx", 0).toInt();
    int dy = settings.value("scharr_filter_settings_dy", 1).toInt();

    cv::Scharr(_modified, _modified, CV_8U, dx, dy, scale, delta);
}

void Image::median_filter(void)
{
    save_state();

    QSettings settings(_file_settings,  QSettings::NativeFormat);
    int k_size = settings.value("median_filter_settings_k_size", 3).toInt();

    cv::medianBlur(_modified, _modified, k_size);
}

void Image::sobel_filter(void)
{
    save_state();

    QSettings settings(_file_settings, QSettings::NativeFormat);

    int k_size = settings.value("scharr_filter_settings_k_size", 3).toInt();
    int scale = settings.value("scharr_filter_settings_scale", 1).toInt();
    int delta = settings.value("scharr_filter_settings_delta", 0).toInt();
    int dx = settings.value("scharr_filter_settings_dx", 0).toInt();
    int dy = settings.value("scharr_filter_settings_dy", 1).toInt();

    cv::Sobel(_modified, _modified, CV_8U, dx, dy, k_size, scale, delta);
}

void Image::erode(void)
{
    save_state();

    QSettings settings(_file_settings, QSettings::NativeFormat);
    int k_size = settings.value("erode_filter_settings_k_size", 3).toInt();
    int shape = settings.value("erode_filter_settings_shape", 0).toInt();

    cv::Mat element = cv::getStructuringElement(shape, cv::Size(k_size, k_size));
    cv::erode(_modified, _modified, element);
}

void Image::dilate(void)
{
    save_state();

    QSettings settings(_file_settings, QSettings::NativeFormat);
    int k_size = settings.value("dilate_filter_settings_k_size", 3).toInt();
    int shape = settings.value("dilate_filter_settings_shape", 0).toInt();

    cv::Mat element = cv::getStructuringElement(shape, cv::Size(k_size, k_size));
    cv::dilate(_modified, _modified, element);
}

void Image::opening(void)
{
    save_state();

    QSettings settings(_file_settings, QSettings::NativeFormat);
    int k_size = settings.value("opening_filter_settings_k_size", 3).toInt();
    int shape = settings.value("opening_filter_settings_shape", 0).toInt(); // cv::MORPH_RECT per default

    cv::Mat element = cv::getStructuringElement(shape, cv::Size(k_size,k_size));
    cv::Mat dst;
    cv::erode(_modified, dst, element);
    cv::dilate(dst, _modified, element);
}

void Image::closing(void)
{
    save_state();

    QSettings settings(_file_settings, QSettings::NativeFormat);
    int k_size = settings.value("closing_filter_settings_k_size", 3).toInt();
    int shape = settings.value("closing_filter_settings_shape", 0).toInt(); // cv::MORPH_RECT per default

    cv::Mat element = cv::getStructuringElement(shape, cv::Size(k_size,k_size));
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




