// MyFilters.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Sfml");
	cv::Mat image = cv::imread("../lena.png");
	cv::Mat imageRGBA;
	sf::Image img_sfml;
	sf::Texture texture;
	sf::Sprite sprite;

	cv::cvtColor(image, imageRGBA, cv::COLOR_BGR2BGRA);
	img_sfml.create(imageRGBA.cols, imageRGBA.rows, imageRGBA.ptr());
	if (!texture.loadFromImage(img_sfml))
		return -1;
	sprite.setTexture(texture);
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}
	return 0;
}