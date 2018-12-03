#pragma once
#include "Image.h"
#include "Button.h"

class IFilter {
	std::shared_ptr<Button>		_button;
	std::unique_ptr<Image>		_preview;

public:
	virtual					~IFilter() = default;
	virtual void			applyFilter(Image &img) = 0;
	
	std::shared_ptr<Button> const	getButton() const {
		return _button;
	}
	void		createPreview(Image &img, float x, float y, float height, float width) {
		_preview = std::make_unique<Image>(x, y, width, height);
		_button = std::make_shared<Button>(x, y, width, height);
		_preview->setRawImage(img.getRawImage().clone());
		applyFilter(*_preview);
		_button->setButtonImage(*_preview);
	}
};