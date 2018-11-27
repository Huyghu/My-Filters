#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class InputBox {
	std::string _text;
	sf::Text _printedText;
	sf::Font _font;
	sf::RectangleShape _box;

public:
	InputBox(float x, float y, float width, float height);
	~InputBox() = default;

	void refreshText(char);

	sf::RectangleShape const &getInputBoxImage() const;
	sf::Text const &getTextImage() const;
	std::string const &getText() const;
};

