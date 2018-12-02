#include "MyFilters.h"
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "GreyScale.h"
#include "ColorHue.h"
#include "ColorFocus.h"
#include "PixelFilter.h"
#include "ToneFilter.h"
#include "ClarendonFilter.h"
#include "BGRColorHue.h"
#include "VignetFilter.h"

MyFilters::MyFilters() :
	_window(sf::VideoMode(700, 700), "My Filters"), _downloadButton("../Assets/download.jpg", 400, 600, 135, 39),
	_filePathBox(20, 15, 345, 35), _loadImageButton("../Assets/GoButton.png", 370, 15, 35, 35), _outputImage(50, 50, 500, 500)
{
    filters["GreyScale"] = std::make_unique<GreyScale>();
    filters["BlueHue"] = std::make_unique<ColorHue>(0);
    filters["GreenHue"] = std::make_unique<ColorHue>(1);
    filters["RedHue"] = std::make_unique<ColorHue>(2);
    filters["BlueFocus"] = std::make_unique<ColorFocus>(0);
    filters["GreenFocus"] = std::make_unique<ColorFocus>(1);
    filters["RedFocus"] = std::make_unique<ColorFocus>(2);
    filters["SmallPixel"] = std::make_unique<PixelFilter>();
    filters["Brigther"] = std::make_unique<ToneFilter>(ToneCurve::Linear, 20);
    filters["Darker"] = std::make_unique<ToneFilter>(ToneCurve::Linear, -20);
    filters["MoreContrast"] = std::make_unique<ToneFilter>(ToneCurve::Contrast, 0);
    filters["LessContrast"] = std::make_unique<ToneFilter>(ToneCurve::Contrast, 1);
//    filters["GammeFilter"] = std::make_unique<ToneFilter>(ToneCurve::Gamma);  WIP
    filters["RevertTone"] = std::make_unique<ToneFilter>(ToneCurve::Revert);
    filters["Clarendon"] = std::make_unique<ClarendonFilter>();
    filters["Valencia"] = std::make_unique<BGRColorHue>(0, 35, 35);
    filters["Juno"] = std::make_unique<BGRColorHue>(0, 35, 70);
    filters["Lark"] = std::make_unique<BGRColorHue>(10, 10, -25); //ToCheck

    filters["testVignet"] = std::make_unique<VignetFilter>(0, 50);
}

void MyFilters::go()
{
	while (_window.isOpen()) {
		sf::Event event;

		while (_window.pollEvent(event)) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(_window);
			sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

			if (event.type == sf::Event::Closed)
				_window.close();
			if (event.type == sf::Event::MouseMoved) {
				_downloadButton.checkMouseOver(mousePosF);
				_loadImageButton.checkMouseOver(mousePosF);
			}
			if (event.type == sf::Event::TextEntered)
				_filePathBox.refreshText(static_cast<char>(event.text.unicode));
			if (event.type == sf::Event::MouseButtonPressed) {
				if (_loadImageButton.isClicked(mousePosF))
					loadImage(_filePathBox.getText());
			}
		}

		_window.clear(sf::Color::White);
		_window.draw(_downloadButton.getButtonImage());
		_window.draw(_filePathBox.getInputBoxImage());
		_window.draw(_filePathBox.getTextImage());
		_window.draw(_loadImageButton.getButtonImage());
		_window.draw(_outputImage.getImage());
		_window.display();
	}
}

void MyFilters::loadImage(std::string const &imagePath)
{
	try {
		_outputImage.loadImage(imagePath);
//        filters["GreyScale"]->applyFilter(_outputImage);
        filters["testVignet"]->applyFilter(_outputImage);
    }
	catch (std::exception e) {
		//OUTPUT ERROR
		return;
	}
}
