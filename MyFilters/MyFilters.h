#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

class MyFilters {
	sf::RenderWindow _window;
	Button _downloadButton;

public:
	MyFilters();
	~MyFilters() = default;

	void go();

};
