#include "pch.h"
#include "MyFilters.h"
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

MyFilters::MyFilters() :
	_window(sf::VideoMode(700, 700), "My Filters"), _downloadButton("../Assets/download.jpg", 400, 600, 135, 39)
{
}

void MyFilters::go()
{
	/*cv::Mat image = cv::imread("../lena.png");
	cv::Mat imageRGBA;
	sf::Image img_sfml;
	sf::Texture texture;
	sf::Sprite sprite;

	cv::cvtColor(image, imageRGBA, cv::COLOR_BGR2BGRA);
	img_sfml.create(imageRGBA.cols, imageRGBA.rows, imageRGBA.ptr());
	if (!texture.loadFromImage(img_sfml))
		throw std::exception();
	sprite.setTexture(texture);*/

	while (_window.isOpen()) {
		sf::Event event;

		while (_window.pollEvent(event)) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(_window);
			sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

			if (event.type == sf::Event::Closed)
				_window.close();
			if (event.type == sf::Event::MouseMoved)
				_downloadButton.checkMouseOver(mousePosF);
		}

		_window.clear(sf::Color::White);
		_window.draw(_downloadButton.getButtonImage());
		_window.display();
	}
}
