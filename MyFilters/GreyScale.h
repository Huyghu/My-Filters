#pragma once
#include "IFilter.h"

class GreyScale : public IFilter {

public:
	GreyScale() {}
	~GreyScale() = default;
	void		applyFilter(Image &img);
};