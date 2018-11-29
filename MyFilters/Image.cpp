#include "Image.h"
#include <iostream>

Image::Image(float x, float y, float width, float height) {
	_sprite.setPosition(x, y);
}

sf::Sprite const	&Image::getImage() const {
	return _sprite;
}

void				Image::reloadImage() {
	sf::Image img_sfml;
	cv::Mat tmp;
	cv::cvtColor(_cvImage, tmp, cv::COLOR_RGB2BGRA);
	img_sfml.create(tmp.cols, tmp.rows, tmp.ptr());
	if (!_texture.loadFromImage(img_sfml))
		throw std::exception();
	_sprite.setTexture(_texture);
}

int					Image::loadImage(std::string const &imagePath) {
	_cvImage = cv::imread("../Assets/" + imagePath);
	if (_cvImage.data == NULL)
		throw std::exception();
	reloadImage();
}

cv::Mat const		&Image::getRawImage() const {
	return _cvImage;
}