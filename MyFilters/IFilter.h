#pragma once
#include "Image.h"

class IFilter {
public:
	virtual ~IFilter() = default;
	virtual void	applyFilter(Image &img) = 0;
};