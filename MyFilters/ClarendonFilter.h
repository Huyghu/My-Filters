#pragma once
#include "IFilter.h"

class ClarendonFilter : public IFilter {

public:
    ClarendonFilter() {}
    ~ClarendonFilter() = default;
    void		applyFilter(Image &img);
};