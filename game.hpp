#include "window.hpp"

class Game {
	public:
		Game();
		~Game();

		void HandleInput();
		void Update();
		void Render();
		void RestartClock();
		Window* GetWindow();
		sf::Time GetElapsed();

	private:
		void MoveMushroom();
		sf::Texture m_mushroomTexture;
		sf::Sprite m_mushroom;
		sf::Vector2i m_increment;
		sf::Clock m_clock;
		sf::Time m_elapsed;
		Window m_window;
};

Game::Game(): m_window("Snake", sf::Vector2u(800, 600)) {
	// Setting up class members
	m_mushroomTexture.loadFromFile("assets/img/mushroom.png");
	m_mushroom.setTexture(m_mushroomTexture);
	m_increment = sf::Vector2i(400, 400);		// 400px a second
}

Game::~Game() {}

void Game::HandleInput() {}

void Game::Update() {
	m_window.Update();
	MoveMushroom();
}

void Game::MoveMushroom() {
	sf::Vector2u l_windSize = m_window.GetWindowSize();
	sf::Vector2u l_textSize = m_mushroomTexture.getSize();

	if((m_mushroom.getPosition().x > l_windSize.x - l_textSize.x && m_increment.x > 0)
		|| (m_mushroom.getPosition().x < 0 && m_increment.x < 0)) {
			m_increment.x = -m_increment.x;
	}

	if((m_mushroom.getPosition().y > l_windSize.y - l_textSize.y && m_increment.y > 0) 
		|| (m_mushroom.getPosition().y < 0 && m_increment.y < 0)) {
			m_increment.y = -m_increment.y;
	}

	float fElapsed = m_elapsed.asSeconds();

	m_mushroom.setPosition(m_mushroom.getPosition().x + (m_increment.x * fElapsed), 
												 m_mushroom.getPosition().y + (m_increment.y * fElapsed));
}

void Game::Render() {
	m_window.BeginDraw();
	m_window.Draw(m_mushroom);
	m_window.EndDraw();
}

Window *Game::GetWindow() {}

sf::Time Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed = m_clock.restart(); }