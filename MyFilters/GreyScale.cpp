#include "GreyScale.h"

void	GreyScale::applyFilter(Image &img) {
	cv::Mat	tmp = img.getRawImage();

	for (int y = 0; y < tmp.rows ; y++) {
		for (int x = 0; x < tmp.cols; x++) {
			int intensity = tmp.at<cv::Vec3b>(y, x)[1];
			for (int c = 0; c < tmp.channels(); c++) {
				tmp.at<cv::Vec3b>(y, x)[c] = intensity;
			}
		}
	}
	img.reloadImage();
}