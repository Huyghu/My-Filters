#include "pch.h"
#include "InputBox.h"
#include <iostream>

InputBox::InputBox(float x, float y, float width, float height) :
	_text(""), _box(sf::Vector2f(width, height)), _font(), _printedText()
{
	_box.setPosition(x, y);
	_box.setOutlineThickness(2);
	_box.setFillColor(sf::Color::White);
	_box.setOutlineColor(sf::Color(0, 0, 0));

	if (!_font.loadFromFile("../Assets/BodoniXT.ttf")) {
		std::cout << "Can't find font" << std::endl;
		throw new std::exception();
	}
	_printedText.setFont(_font);
	_printedText.setCharacterSize(20);
	_printedText.setPosition(x, y);
	_printedText.setFillColor(sf::Color::Black);
}

void InputBox::refreshText(char c)
{
	if (static_cast<int>(c) == 8)
		_text = _text.substr(0, _text.size() - 1);
	else
		_text += c;
	_printedText.setString(_text);
}

sf::RectangleShape const &InputBox::getInputBoxImage() const
{
	return _box;
}

sf::Text const &InputBox::getTextImage() const 
{
	return _printedText;
}

std::string const &InputBox::getText() const
{
	return _text;
}

