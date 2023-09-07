#include "car.hpp"
#include "road.hpp"

Car::Car(float x, Road& road, float speed, float y, sf::Color color)
    : carSpeed(speed), roadReference(road), initialX(x)
{
    carShape.setSize(sf::Vector2f(70.0f, 40.0f));
    carShape.setFillColor(color);


    carShape.setPosition(x, y); // Use the provided 'y' position
}

void Car::move(float dt)
{
    float newX = carShape.getPosition().x + carSpeed * dt;

    // Check if the car has moved past the right edge of the screen
    if (newX > static_cast<float>(roadReference.getWindowWidth()))
    {
        newX = -50.0f; // Set the car back to the start
    }

    carShape.setPosition(newX, carShape.getPosition().y);
}

void Car::draw(sf::RenderWindow& window) const
{
    window.draw(carShape);
}

sf::FloatRect Car::getCollisionRect() const {
    return carShape.getGlobalBounds();
}