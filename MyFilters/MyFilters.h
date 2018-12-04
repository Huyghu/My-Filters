#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "InputBox.h"
#include "Image.h"
#include <unordered_map>
#include "IFilter.h"

class MyFilters {
	sf::RenderWindow _window;
	Button			_downloadButton;
	Button			_resetButton;
	Button			_loadImageButton;
	InputBox		_filePathBox;
	InputBox		_savePath;
	Image			_outputImage;
	Image			_savedImage;
	bool			_isLoad;
	std::unordered_map<std::string, std::unique_ptr<IFilter>> filters;

public:
	MyFilters();
	~MyFilters() = default;

	void go();

private:
	void	loadImage(std::string const &);
	void	resetImage();
	void	downloadImage();
};
