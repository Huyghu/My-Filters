#include "pch.h"
#include <iostream>
#include "Button.h"

Button::Button(std::string const &imagePath, float x, float y, float width, float height) :
	_buttonImage(sf::Vector2f(width, height))
{
	if (!_button.loadFromFile(imagePath))
		std::cout << "Can't find file: " << imagePath << std::endl;
	_buttonImage.setTexture(&_button);
	_buttonImage.setPosition(x, y);
}

sf::RectangleShape const &Button::getButtonImage() const
{
	return _buttonImage;
}

bool Button::isClicked(sf::Vector2f const &mousePos) const
{
	return _buttonImage.getGlobalBounds().contains(mousePos);
}

void Button::checkMouseOver(sf::Vector2f const &mousePos)
{
	if (_buttonImage.getGlobalBounds().contains(mousePos)) {
		_buttonImage.setOutlineThickness(3);
		_buttonImage.setOutlineColor(sf::Color(250, 150, 100));
	}
	else {
		_buttonImage.setOutlineThickness(0);
	}
}
