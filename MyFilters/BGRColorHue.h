#pragma once
#include "IFilter.h"

class BGRColorHue : public IFilter {

public:
    BGRColorHue(int blue_ = 0, int green_ = 0, int red_ = 0) : blue(blue_), green(green_), red(red_) { }
    ~BGRColorHue() = default;
    void		applyFilter(Image &img);
private:
    int blue, green, red;
};