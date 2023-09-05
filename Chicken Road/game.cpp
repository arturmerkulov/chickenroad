#include "game.hpp"
#include "settings.hpp"


Game::Game()
	: m_window({ setting::WINDOW_WIDTH, setting::WINDOW_HEIGHT }, "Tetris"),
	m_board(), 
	m_tetrominoController(m_board) 
{
}

Game::~Game()
{
	for (auto tetromino : m_tetrominoes) {
		delete tetromino;
	}
}

	void Game::run()
{
	tetrominoFillColor = sf::Color::Red;
	tetrominoPosition = sf::Vector2f(100.0f, 100.0f);

	sf::Clock clock;
	while (m_window.isOpen())


	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			handleEvent(event);
		}

		sf::Time elapsed = clock.restart();
		tick(elapsed.asSeconds());

		m_window.clear(sf::Color::Black);
		render();
		m_window.display();
	}
}

void Game::exit()
{
	m_window.close();
}

void Game::draw(const sf::Drawable& shape)
{
	m_window.draw(shape);
}

void Game::tick(float dt)
{
	if (isGameOver)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			restartGame();
		}

		return;
	}
}

void Game::render()
{
	m_window.clear(sf::Color::Black);

	for (const auto& tetromino : m_tetrominoes) {
		tetromino->render(m_window, tetromino->getPosition(), tetromino->getFillColor());
	}

	m_window.display();
}

void Game::handleEvent(const sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::Closed:
		exit();
		break;
	}
}

void Game::restartGame()
{
	isGameOver = false;
}

void Game::gameOver()
{
	if (isGameOver)
	{
		return;
	}

	isGameOver = true;
}