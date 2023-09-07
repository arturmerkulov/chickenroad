#include "chicken.hpp"
#include "settings.hpp"
#include "game.hpp"

Chicken::Chicken(float x, float y)
	: topThreshold(50.0f)
{
	shape.setSize(sf::Vector2f(50.0f, 50.0f));
	shape.setFillColor(sf::Color::Yellow);
	position.x = x;
	position.y = y;
	shape.setPosition(position);
}

void Chicken::move(float xOffset, float yOffset)
{
	position.x += xOffset;
	position.y += yOffset;

	float screenWidth = static_cast<float>(setting::WINDOW_WIDTH);
	float screenHeight = static_cast<float>(setting::WINDOW_HEIGHT);

	if (position.x < 0)
	{
		position.x = 0;
	}
	else if (position.x > screenWidth - shape.getSize().x)
	{
		position.x = screenWidth - shape.getSize().x;
	}
	if (position.y < 0)
	{
		position.y = 0;
	}
	else if (position.y > screenHeight - shape.getSize().y)
	{
		position.y = screenHeight - shape.getSize().y;
	}
	// Check if the chicken has reached the top of the screen
	if (position.y < topThreshold) {
		position.y = screenHeight - shape.getSize().y; // Reset to the bottom
	}
	else if (position.y > screenHeight - shape.getSize().y) {
		position.y = screenHeight - shape.getSize().y;
	}

	shape.setPosition(position);
}

void Chicken::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Chicken::setPosition(float x, float y) {
	position.x = x;
	position.y = y;
	shape.setPosition(position);
}

sf::FloatRect Chicken::getCollisionRect() const {
	return shape.getGlobalBounds();
}