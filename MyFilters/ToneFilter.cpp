#include "ToneFilter.h"

ToneFilter::ToneFilter(ToneCurve curve_, int intensity_)
{
    switch (curve_)
    {
    case ToneCurve::Linear:
        for (int i = 0; i < 256; ++i)
            curve.push_back(i);
        break;
    case ToneCurve::Brightness:
        for (int i = 0; i < 256; ++i) {
            int buf = i;
            if (buf + intensity_ > 255)
                buf = 255;
            else if (buf + intensity_ < 0)
                buf = 0;
            else
                buf += intensity_;
            curve.push_back(buf);
        }
        break;
    case ToneCurve::Contrast:
        for (int i = 0; i < 256; ++i) {
            int bufX = i;
            int bufY = i;

            int angle = (intensity_) ? 75 : 125;

            float s = std::sin(angle);
            float c = std::cos(angle);

            bufX -= 128;
            bufY -= 128;

            float xnew = bufX * c - bufY * s;
            float ynew = bufX * s + bufY * c;

            bufX = xnew + 128;
            bufY = ynew + 128;

            if (bufX < 0)
                bufX = 0;
            if (bufX > 255)
                bufX = 255;
            if (intensity_)
                curve.push_back(bufY);
            else
                curve.push_back(bufX);
        }
        break;
    case ToneCurve::Gamma:
        for (int i = 0; i < 256; ++i)
            curve.push_back(i);
        //TBD
        break;
    case ToneCurve::Revert:
        for (int i = 0; i < 256; ++i)
            curve.push_back(255 - i);
        break;

    }
}

void	ToneFilter::applyFilter(Image &img) {
    cv::Mat	tmp = img.getRawImage();

    for (int y = 0; y < tmp.rows; y++) {
        for (int x = 0; x < tmp.cols; x++) {
            for (int c = 0; c < tmp.channels(); c++) {
                tmp.at<cv::Vec3b>(y, x)[c] = curve[tmp.at<cv::Vec3b>(y, x)[c]];
            }
        }
    }
    img.reloadImage();
}