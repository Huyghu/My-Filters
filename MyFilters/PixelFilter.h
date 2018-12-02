#pragma once
#include "IFilter.h"

class PixelFilter : public IFilter {

public:
    PixelFilter(int resolution_ = 3) : resolution(resolution_) { }
    ~PixelFilter() = default;
    void		applyFilter(Image &img);
private:
    int resolution;
};