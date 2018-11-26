#pragma once
#include <SFML/Graphics.hpp>

class Button {

	sf::Texture _button;
	sf::Sprite _buttonImage;
	float _x;
	float _y;

public:
	Button(std::string const &imagePath, float x, float y, float width, float height);
	~Button() = default;

	sf::Sprite const &getButtonImage() const;
	bool isClicked(sf::Vector2f const &) const;
};