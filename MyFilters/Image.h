#pragma once
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class Image {
	
	sf::Texture _texture;
	sf::Sprite _sprite;

public:
	Image(float x, float y, float width, float height);
	~Image() = default;

	int					loadImage(std::string const &imagePath);
	sf::Sprite const	&getImage() const;
};