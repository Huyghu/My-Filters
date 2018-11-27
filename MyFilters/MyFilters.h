#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "InputBox.h"

class MyFilters {
	sf::RenderWindow _window;
	Button _downloadButton;
	InputBox _filePathBox;
	Button _loadImageButton;

public:
	MyFilters();
	~MyFilters() = default;

	void go();

private:
	void loadImage(std::string const &);

};
