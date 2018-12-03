#pragma once
#include "IFilter.h"

class GreyScale : public IFilter {
public:
	GreyScale() = default;
	~GreyScale() = default;
	void		applyFilter(Image &img);
};