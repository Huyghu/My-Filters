#pragma once
#include "IFilter.h"

enum ToneCurve
{
    Linear = 0,
    Brightness = 1,
    Contrast = 2,
    Gamma = 3,
    Revert = 4
};

class ToneFilter : public IFilter {

public:
    ToneFilter(ToneCurve curve_ = ToneCurve::Linear, int intensity_ = 0);
    ~ToneFilter() = default;
    void		applyFilter(Image &img);
private:
    std::vector<uchar> curve;
};