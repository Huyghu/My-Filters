#include "ColorFocus.h"

void	ColorFocus::applyFilter(Image &img) {
    cv::Mat	tmp = img.getRawImage();

    for (int y = 0; y < tmp.rows; y++) {
        for (int x = 0; x < tmp.cols; x++) {
            int intensity = tmp.at<cv::Vec3b>(y, x)[1];
            for (int c = 0; c < tmp.channels(); c++) {
                if (c == color) {
                    if (tmp.at<cv::Vec3b>(y, x)[color] <= 234)
                        tmp.at<cv::Vec3b>(y, x)[color] += 20;
                    else
                        tmp.at<cv::Vec3b>(y, x)[color] = 254;
                }
                else {
                    tmp.at<cv::Vec3b>(y, x)[c] = intensity;
                }
            }
        }
    }
    img.reloadImage();
}