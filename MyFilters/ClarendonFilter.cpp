#include "ClarendonFilter.h"

void	ClarendonFilter::applyFilter(Image &img) {
    cv::Mat	tmp = img.getRawImage();

    for (int y = 0; y < tmp.rows; y++) {
        for (int x = 0; x < tmp.cols; x++) {
            int intensity = tmp.at<cv::Vec3b>(y, x)[1];
            for (int c = 0; c < tmp.channels(); c++) {
                if (intensity > 128) {
                    if (tmp.at<cv::Vec3b>(y, x)[c] <= 235)
                        tmp.at<cv::Vec3b>(y, x)[c] += 20;
                    else
                        tmp.at<cv::Vec3b>(y, x)[c] = 255;
                } else {
                    if (tmp.at<cv::Vec3b>(y, x)[c] >= 20)
                        tmp.at<cv::Vec3b>(y, x)[c] -= 20;
                    else
                        tmp.at<cv::Vec3b>(y, x)[c] = 0;
                }
            }
        }
    }
    img.reloadImage();
}