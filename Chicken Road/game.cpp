#include "game.hpp"
#include "settings.hpp"


Game::Game()
	: m_window({ setting::WINDOW_WIDTH, setting::WINDOW_HEIGHT }, "Chicken Road"),
	chicken(setting::WINDOW_WIDTH / 2, setting::WINDOW_HEIGHT - 100),
	road(sf::Color::White, setting::WINDOW_HEIGHT / 4.0f)
{
	m_window.setVerticalSyncEnabled(true); // call it once, after creating the window
	// Calculate Y positions for the cars to be in the middle of the road
	float carY = road.getMiddle() - 25.0f; // Half of the car height

	// Create and initialize cars
	cars.emplace_back(setting::WINDOW_WIDTH / 2 - 25.0f, road, 100.0f, road.getMiddle() - 70.0f, sf::Color::Red);
	cars.emplace_back(setting::WINDOW_WIDTH / 2 - 75.0f, road, 150.0f, road.getMiddle() -25.0f, sf::Color::Blue);
	cars.emplace_back(setting::WINDOW_WIDTH / 2 - 50.0f, road, 120.0f, road.getMiddle() +30.0f, sf::Color::Green);
}

Game::~Game()
{
}

	void Game::run()
{
	

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
		
		handleInput();

		m_window.clear(sf::Color::Black);
		render();
		m_window.display();

		for (Car& car : cars)
		{
			car.move(elapsed.asSeconds());
			car.draw(m_window);
		}
	}
}

	void Game::handleInput()
	{
		float chickenSpeed = 5.0f;
		float xOffset = 0.0f;
		float yOffset = 0.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			xOffset = -chickenSpeed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			xOffset = chickenSpeed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			yOffset = -chickenSpeed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			yOffset = chickenSpeed;
		}

		chicken.move(xOffset, yOffset);
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
	// Check for collisions with cars
	sf::FloatRect chickenRect = chicken.getCollisionRect();
	for (Car& car : cars) {
		if (car.getCollisionRect().intersects(chickenRect)) {
			// Collision detected
			chicken.setPosition(setting::WINDOW_WIDTH / 2, setting::WINDOW_HEIGHT - 100); // Reset chicken position
		}
		car.move(dt);
	}

	for (Car& car : cars)
	{
		car.move(dt);
	}
}

void Game::render()
{
	m_window.clear(sf::Color::Black);
	road.draw(m_window);

	for (Car& car : cars)
	{
		car.draw(m_window);
	}

	chicken.draw(m_window);
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
