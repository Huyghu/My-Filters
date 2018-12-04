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
	_window(sf::VideoMode(1200, 800), "My Filters"), 
	_downloadButton("../Assets/download2.png", 370, 730, 35, 35), 
	_resetButton("../Assets/reload.png", 430, 15, 35, 35),
	_loadImageButton("../Assets/GoButton.png", 370, 15, 35, 35),
	_filePathBox(20, 15, 345, 35),
	_savePath(20, 730, 345, 35),
	_outputImage(20, 60, 500, 650),
	_savedImage(20, 60, 500, 650),
	_isLoad(false)
{
    filters["GreyScale"] = std::make_unique<GreyScale>();
    filters["BlueHue"] = std::make_unique<ColorHue>(0);
    filters["GreenHue"] = std::make_unique<ColorHue>(1);
    filters["RedHue"] = std::make_unique<ColorHue>(2);
    filters["BlueFocus"] = std::make_unique<ColorFocus>(0);
    filters["GreenFocus"] = std::make_unique<ColorFocus>(1);
    filters["RedFocus"] = std::make_unique<ColorFocus>(2);
    filters["SmallPixel"] = std::make_unique<PixelFilter>(4);
    filters["Brigther"] = std::make_unique<ToneFilter>(ToneCurve::Brightness, 20);
    filters["Darker"] = std::make_unique<ToneFilter>(ToneCurve::Brightness, -20);   
    filters["MoreContrast"] = std::make_unique<ToneFilter>(ToneCurve::Contrast, 0);
    filters["LessContrast"] = std::make_unique<ToneFilter>(ToneCurve::Contrast, 1);
//    filters["GammeFilter"] = std::make_unique<ToneFilter>(ToneCurve::Gamma);  WIP
    filters["RevertTone"] = std::make_unique<ToneFilter>(ToneCurve::Revert);
    filters["Clarendon"] = std::make_unique<ClarendonFilter>();
    filters["Valencia"] = std::make_unique<BGRColorHue>(0, 35, 35);
    filters["Juno"] = std::make_unique<BGRColorHue>(0, 35, 70);
    filters["Lark"] = std::make_unique<BGRColorHue>(10, 10, -25);
    filters["Perpetua"] = std::make_unique<BGRColorHue>(15, 45, 30);
    filters["Amaro"] = std::make_unique<VignetFilter>(0, 60, 0, 15, 15);
    filters["Mayfair"] = std::make_unique<VignetFilter>(1, 60, 20, 5, 5);
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
				_resetButton.checkMouseOver(mousePosF);
			}
			if (event.type == sf::Event::TextEntered)
				_filePathBox.refreshText(static_cast<char>(event.text.unicode));
			if (event.type == sf::Event::TextEntered)
				_savePath.refreshText(static_cast<char>(event.text.unicode));

			if (event.type == sf::Event::MouseButtonPressed) {
				_filePathBox.checkSelected(mousePosF);
				_savePath.checkSelected(mousePosF);
				if (_loadImageButton.isClicked(mousePosF))
					loadImage(_filePathBox.getText());
				if (_isLoad && _resetButton.isClicked(mousePosF))
					resetImage();
				if (_isLoad) {
					for (auto &filter : filters) {
						if (filter.second->getButton()->isClicked(mousePosF)) {
							_outputImage.setRawImage(_savedImage.getRawImage().clone());
							filter.second->applyFilter(_outputImage);
						}
					}
				}
				if (_downloadButton.isClicked(mousePosF))
					downloadImage();
			}
		}

		_window.clear(sf::Color::White);
		_window.draw(_downloadButton.getButtonImage());
		_window.draw(_filePathBox.getInputBoxImage());
		_window.draw(_filePathBox.getTextImage());
		_window.draw(_savePath.getInputBoxImage());
		_window.draw(_savePath.getTextImage());
		_window.draw(_loadImageButton.getButtonImage());
		_window.draw(*_outputImage.getImage());
		_window.draw(_resetButton.getButtonImage());
		if (_isLoad) {
			for (auto &filter : filters) {
				_window.draw(filter.second->getButton()->getButtonImage());
			}
		}
		_window.display();
	}
}

void MyFilters::loadImage(std::string const &imagePath)
{
	try {
		_outputImage.loadImage(imagePath);
		_savedImage.setRawImage(_outputImage.getRawImage().clone());
		_isLoad = true;
		int x = 0, y = 10;
		for (auto &filter : filters) {
			filter.second->createPreview(_outputImage, 600 + x, y, 140, 140);
			x += 145;
			if (600 + x > 1060) {
				x = 0;
				y += 145;
			}
		}
    }
	catch (std::exception e) {
		_outputImage.loadImage("error.jpeg");
		std::cout << "err" << std::endl;
		return;
	}
}

void	MyFilters::resetImage() {
	_outputImage.setRawImage(_savedImage.getRawImage().clone());
}


void	MyFilters::downloadImage() {
	try {
		cv::imwrite(_savePath.getText(), _outputImage.getRawImage());
	}
	catch (std::runtime_error& ex) {
		fprintf(stderr, "Exception downloading the image: %s\n", ex.what());
		return;
	}
}