#include "Image.h"

Image::Image(float x, float y, float width, float height) {
	_sprite.setPosition(x, y);
}

sf::Sprite const	&Image::getImage() const {
	return _sprite;
}

int					Image::loadImage(std::string const &imagePath) {
	sf::Image img_sfml;
	cv::Mat imageRGBA;
	cv::Mat image = cv::imread("../Assets/" + imagePath);

	cv::cvtColor(image, imageRGBA, cv::COLOR_BGR2BGRA);
	img_sfml.create(imageRGBA.cols, imageRGBA.rows, imageRGBA.ptr());
	if (!_texture.loadFromImage(img_sfml))
		throw std::exception();
	_sprite.setTexture(_texture);
}