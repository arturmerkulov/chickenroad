#include "road.hpp"
#include "settings.hpp"

Road::Road(sf::Color color, float roadHeight)
    : roadHeight(roadHeight)
{
    float roadWidth = static_cast<float>(setting::WINDOW_WIDTH);
    float yPos = (static_cast<float>(setting::WINDOW_HEIGHT) - roadHeight) / 2.0f; // Adjust yPos here

    roadShape.setSize(sf::Vector2f(roadWidth, roadHeight));
    roadShape.setFillColor(color);
    roadShape.setPosition(0.0f, yPos);
}

void Road::draw(sf::RenderWindow& window)
{
    window.draw(roadShape);
}

float Road::getRoadHeight() const
{
    return roadHeight;
}

float Road::getMiddle() const
{
    return roadShape.getPosition().y + roadHeight / 2.0f;
}

int Road::getWindowWidth() const
{
    return static_cast<int>(roadShape.getSize().x);
}