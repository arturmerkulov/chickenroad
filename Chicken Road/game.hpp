#pragma once

#include <SFML/Graphics.hpp>
#include "chicken.hpp"
#include "road.hpp"
#include "car.hpp"
#include <deque>

// Singleton
class Game
{
public:
	static Game& getInstance()
	{
		static Game game;
		return game;
	}

	~Game();
	void run();
	void exit();
	void draw(const sf::Drawable& shape);

private:
	Game();
	Game(const Game& otherGame);
	Game& operator=(const Game& otherGame);

	void tick(float dt);
	void render();
	void handleEvent(const sf::Event& event);
	void handleInput();

	void restartGame();
	void gameOver();


private:
	bool isGameOver = false;
	sf::RenderWindow m_window;
	Chicken chicken;
	Road road;
	std::deque<Car> cars;
};