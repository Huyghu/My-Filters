#pragma once
#include "IFilter.h"

class ColorFocus : public IFilter {

public:
    ColorFocus(int color_ = 0) : color(color_) { }
    ~ColorFocus() = default;
    void		applyFilter(Image &img);
private:
    int color;
};