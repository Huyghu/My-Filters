#pragma once
#include "IFilter.h"

class VignetFilter : public IFilter {

public:
    VignetFilter(bool accentuate_ = true, int intensity_ = 0, int blue_ = 0, int green_ = 0, int red_ = 0) : accentuate(accentuate_), intensity(intensity_),
        blue(blue_), green(green_), red(red_) { }
    ~VignetFilter() = default;
    void		applyFilter(Image &img);
private:
    bool accentuate;
    int intensity, blue, green, red;
};