#pragma once
#include "Tetromino.hpp"
#include "Board.hpp"
#include "TetrominoController.hpp"
#include <SFML/Graphics.hpp>
class Board;
class TetrominoController;
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

	sf::Color tetrominoFillColor; 
	sf::Vector2f tetrominoPosition;
	std::vector<Tetromino*> m_tetrominoes; //supposed to be	a vector holding all of the tetrominoes instances
	TetrominoController m_tetrominoController;

	void tick(float dt);
	void render();
	void handleEvent(const sf::Event& event);

	void restartGame();
	void gameOver();


private:
	bool isGameOver = false;
	sf::RenderWindow m_window;
};