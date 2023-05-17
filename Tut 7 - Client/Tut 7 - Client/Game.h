/// <summary>
/// Author - Adam Mcguigan & Sasa Kuzmanovic
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>
#include "Client.h"
#include "Player.h"

/**
* This is the public game class, inside we have various functions that are used for the main game loop.
*/
class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

	void setupFontAndText();
	void setupSprite();

	sf::RectangleShape getOtherPlayers(); // when the game is started, check if there is any other ID-s. If there is, get the players rectangle, set the position of it and draw it.
	Client myClient;
	Player player;

	std::string playerPosString[2];

	sf::Font m_font;


private:
	/// <summary>
	/// Main method to process any events in the game
	/// </summary>
	void processEvents();
	/// <summary>
	/// Inside this function we handle any key input
	/// </summary>
	void processKeys(sf::Event t_event);
	/// <summary>
	/// This is the main update function for the game
	/// </summary>
	void update(sf::Time t_deltaTime);
	/// <summary>
	/// This is the main Render function
	/// </summary>
	void render();

	void split(std::string string, char seperator);

	int len(std::string string);


	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game


};

#endif // !GAME_HPP