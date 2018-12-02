#include "BGRColorHue.h"

void	BGRColorHue::applyFilter(Image &img) {
    cv::Mat	tmp = img.getRawImage();

    if (tmp.channels() < 3)
        return;
    auto lambdaAdd = [](uchar val, int add) {
        int buf = val + add;
        if (buf < 0)
            return 0;
        else if (buf > 255)
            return 255;
        else
            return buf;
    };
    for (int y = 0; y < tmp.rows; y++) {
        for (int x = 0; x < tmp.cols; x++) {
            tmp.at<cv::Vec3b>(y, x)[0] = lambdaAdd(tmp.at<cv::Vec3b>(y, x)[0], blue);
            tmp.at<cv::Vec3b>(y, x)[1] = lambdaAdd(tmp.at<cv::Vec3b>(y, x)[1], green);
            tmp.at<cv::Vec3b>(y, x)[2] = lambdaAdd(tmp.at<cv::Vec3b>(y, x)[2], red);
        }
    }
    img.reloadImage();
}