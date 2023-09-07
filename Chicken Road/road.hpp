#pragma once

#include <SFML/Graphics.hpp>

class Road
{
public:
	Road(sf::Color color, float height);
	void draw(sf::RenderWindow& window);
	float getMiddle() const;
	float getRoadHeight() const;
	int getWindowWidth() const;
private:
	sf::RectangleShape roadShape;
	float roadHeight;
};