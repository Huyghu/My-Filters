#include "Image.h"
#include <iostream>

Image::Image(float x, float y, float width, float height) : _x(x), _y(y), _width(width), _height(height) {
	initSprite();
}

std::shared_ptr<sf::Sprite> const	Image::getImage() const {
	return _sprite;
}

void				Image::initSprite() {
	_sprite = std::make_shared<sf::Sprite>();
	_sprite->setPosition(_x, _y);
}

void				Image::reloadImage() {
	sf::Image img_sfml;
	cv::Mat tmp;
	cv::cvtColor(_cvImage, tmp, cv::COLOR_RGB2BGRA);
	img_sfml.create(tmp.cols, tmp.rows, tmp.ptr());
	if (!_texture.loadFromImage(img_sfml))
		throw std::exception();
	_sprite->setTexture(_texture);
	sf::FloatRect dim = _sprite->getGlobalBounds();
	if (dim.height > _height || dim.width > _width) {
		_sprite->scale(sf::Vector2f(_width / dim.width,
			_height / dim.height));
	}
}

int					Image::loadImage(std::string const &imagePath) {
	initSprite();
	_cvImage = cv::imread("../Assets/" + imagePath);
	if (_cvImage.data == NULL)
		throw std::exception();
	reloadImage();
}

cv::Mat const		&Image::getRawImage() const {
	return _cvImage;
}