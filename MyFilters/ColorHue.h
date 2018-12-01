#pragma once
#include "IFilter.h"

class ColorHue : public IFilter {

public:
    ColorHue(int color_ = 0) : color(color_) { }
    ~ColorHue() = default;
    void		applyFilter(Image &img);
private:
    int color;
};