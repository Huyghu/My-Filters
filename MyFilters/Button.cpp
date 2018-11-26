#include "pch.h"
#include <iostream>
#include "Button.h"

Button::Button(std::string const &imagePath, float x, float y, float width, float height)
{
	if (!_button.loadFromFile(imagePath))
		std::cout << "Can't find file: " << imagePath << std::endl;
	_buttonImage.setTexture(_button);
	_buttonImage.setPosition(x, y);
	_buttonImage.setScale(width / _button.getSize().x, height / _button.getSize().y);
}

sf::Sprite const &Button::getButtonImage() const
{
	return _buttonImage;
}

bool Button::isClicked(sf::Vector2f const &mousePos) const
{
	return _buttonImage.getGlobalBounds().contains(mousePos);
}
