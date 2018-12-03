#pragma once
#include <SFML/Graphics.hpp>
#include "Image.h"

class Button {

	sf::Texture _button;
	sf::RectangleShape _buttonImage;
	float _x;
	float _y;
	float _width;
	float _height;

public:
	Button(float x, float y, float width, float height);
	Button(std::string const &imagePath, float x, float y, float width, float height);
	~Button() = default;

	sf::RectangleShape const	&getButtonImage() const;
	void						setButtonImage(Image &img);
	bool isClicked(sf::Vector2f const &) const;
	void checkMouseOver(sf::Vector2f const &);
};