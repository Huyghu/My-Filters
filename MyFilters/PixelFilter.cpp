#include "PixelFilter.h"

void	PixelFilter::applyFilter(Image &img) {
    cv::Mat	tmp = img.getRawImage();

    for (int y = 0; y < tmp.rows; y++) {
        for (int x = 0; x < tmp.cols; x++) {
            int yP = y - y % resolution;
            int xP = x - x % resolution;
            int n1 = y % (resolution * 2);
            int n2 = x % (resolution * 2);
            if (n1 >= resolution || n2 >= resolution)
                for (int c = 0; c < tmp.channels(); c++)
                    tmp.at<cv::Vec3b>(y, x)[c] = 0;
            else
                for (int c = 0; c < tmp.channels(); c++)
                    tmp.at<cv::Vec3b>(y, x)[c] = tmp.at<cv::Vec3b>(yP, xP)[c];
        }
    }
    img.reloadImage();
}