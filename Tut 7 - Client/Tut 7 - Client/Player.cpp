#include "Player.h"


void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(playerBox);
}

void Player::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		playerBox.move(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		playerBox.move(0, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		playerBox.move(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		playerBox.move(1, 0);
	}
}

void Player::init()
{
	playerBox.setFillColor(sf::Color::Yellow);
	playerBox.setSize(sf::Vector2f(10.0f, 10.0f));
	playerBox.setPosition(100.0f, 100.0f);
	playerBox.setOrigin(5.0f, 5.0f);
}
