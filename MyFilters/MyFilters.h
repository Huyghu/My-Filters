#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "InputBox.h"
#include "Image.h"

class MyFilters {
	sf::RenderWindow _window;
	Button			_downloadButton;
	Button			_loadImageButton;
	InputBox		_filePathBox;
	Image			_outputImage;

public:
	MyFilters();
	~MyFilters() = default;

	void go();

private:
	void loadImage(std::string const &);

};
