#include "VignetFilter.h"

void	VignetFilter::applyFilter(Image &img) {
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
    
    int maxDist = (tmp.rows + tmp.cols) / 2;
    for (int y = 0; y < tmp.rows; y++) {
        for (int x = 0; x < tmp.cols; x++) {
            int dist = (std::abs(y - tmp.rows) + std::abs(x - tmp.cols)) / maxDist - 0.5; //TBD Check result and factor accentuate
            
            tmp.at<cv::Vec3b>(y, x)[0] = lambdaAdd(tmp.at<cv::Vec3b>(y, x)[0], intensity*dist);
            tmp.at<cv::Vec3b>(y, x)[1] = lambdaAdd(tmp.at<cv::Vec3b>(y, x)[1], intensity*dist);
            tmp.at<cv::Vec3b>(y, x)[2] = lambdaAdd(tmp.at<cv::Vec3b>(y, x)[2], intensity*dist);

            tmp.at<cv::Vec3b>(y, x)[0] = lambdaAdd(tmp.at<cv::Vec3b>(y, x)[0], blue*dist);
            tmp.at<cv::Vec3b>(y, x)[1] = lambdaAdd(tmp.at<cv::Vec3b>(y, x)[1], green*dist);
            tmp.at<cv::Vec3b>(y, x)[2] = lambdaAdd(tmp.at<cv::Vec3b>(y, x)[2], red*dist);
        }
    }
    img.reloadImage();
}
