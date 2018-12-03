#pragma once
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class Image {
	cv::Mat						_cvImage;
	sf::Texture					_texture;
	std::shared_ptr<sf::Sprite>	_sprite;
	float		_x;
	float		_y;
	float		_width;
	float		_height;

	void				initSprite();

public:
	Image(float x, float y, float width, float height);
	~Image() = default;

	int					loadImage(std::string const &imagePath);
	void				reloadImage();
	std::shared_ptr<sf::Sprite> const	getImage() const;
	cv::Mat const		&getRawImage() const;
};