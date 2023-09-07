#pragma once

#include <SFML/Graphics.hpp>

class Chicken
{
public:
    Chicken(float x, float y);
    void move(float xOffset, float yOffset);
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y); 
    sf::FloatRect getCollisionRect() const;
	
private:
	sf::RectangleShape shape;
	sf::Vector2f position;
    float topThreshold;
};