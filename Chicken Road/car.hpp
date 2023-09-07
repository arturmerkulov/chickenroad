#pragma once

#include <SFML/Graphics.hpp>

class Road;

class Car
{
public:
	Car(float x, Road& road, float speed, float y, sf::Color color);

	void move(float dt);
	void draw(sf::RenderWindow& window) const;
	sf::FloatRect getCollisionRect() const;

private:
	sf::RectangleShape carShape;
	float carSpeed;
	Road& roadReference;
	float initialX;
};