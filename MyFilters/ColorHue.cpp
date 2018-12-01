#include "ColorHue.h"

void	ColorHue::applyFilter(Image &img) {
    cv::Mat	tmp = img.getRawImage();

    if (tmp.channels() < color)
        return;
    for (int y = 0; y < tmp.rows; y++) {
        for (int x = 0; x < tmp.cols; x++) {
            if (tmp.at<cv::Vec3b>(y, x)[color] <= 214)
                tmp.at<cv::Vec3b>(y, x)[color] += 40;
            else
                tmp.at<cv::Vec3b>(y, x)[color] = 254;
        }
    }
    img.reloadImage();
}