/// <summary>
/// Adam Mcguigan & Sasa Kuzmanovic
/// 12/2022
/// </summary>

#include "Game.h"
#include <iostream>
#include <iomanip>


Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32U }, "SFML Game" },
	m_exitGame{ false }, //when true game will exit
	myClient("127.0.0.1", 10079)
{

	if (!myClient.Connect()) //If client fails to connect...
	{
		std::cout << "Failed to connect to server..." << std::endl;
		system("pause");
	}

	//myClient.GetNumberOfClients();

	player.init();

	//setupFontAndText();
	setupSprite();
}



Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}


void Game::setupSprite()
{
	/*m_NPCMOVE.setFont(m_font);
	m_NPCMOVE.setFillColor(sf::Color::White);
	m_NPCMOVE.setScale(1.0f, 1.0f);
	m_NPCMOVE.setString("Press H for NPC Move");
	m_NPCMOVE.setPosition(1500.0f, 10.0f);*/
}

sf::RectangleShape Game::getOtherPlayers()
{
	return sf::RectangleShape();
}


void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}


void Game::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//std::string message;
		myClient.SendPlayerPosition(player.getPlayerPosition());
		//myClient.ReturnPlayerPosition(message);
		
		//message = myClient.returnPlayerPos();

		//const char* sep = ",";
		//split(message, *sep);

		//player.playerBox.setPosition(std::stof(playerPosString[0]), std::stof(playerPosString[1]));

		player.playerBox.move(0, -1);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		//std::string message;
		myClient.SendPlayerPosition(player.getPlayerPosition());
		//myClient.ReturnPlayerPosition(message);

		//message = myClient.returnPlayerPos();

		//const char* sep = ",";
		//split(message, *sep);

		//player.playerBox.setPosition(std::stof(playerPosString[0]), std::stof(playerPosString[1]));

		player.playerBox.move(0, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//std::string message;
		myClient.SendPlayerPosition(player.getPlayerPosition());
		//myClient.ReturnPlayerPosition(message);

		//message = myClient.returnPlayerPos();

		//const char* sep = ",";
		//split(message, *sep);

		//player.playerBox.setPosition(std::stof(playerPosString[0]), std::stof(playerPosString[1]));

		player.playerBox.move(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		std::string message;
		myClient.SendPlayerPosition(player.getPlayerPosition());
		//myClient.ReturnPlayerPosition(message);

		//message = myClient.returnPlayerPos();

		//const char* sep = ",";
		//split(message, *sep);

		//player.playerBox.setPosition(std::stof(playerPosString[0]), std::stof(playerPosString[1]));

		player.playerBox.move(1, 0);
	}

	
		

	

	

	if (m_exitGame)
	{
		m_window.close();
	}
}


void Game::render()
{
	m_window.clear(sf::Color::Black);

	player.render(m_window);
	m_window.display();
}

void Game::split(std::string string, char seperator)
{
	int currIndex = 0, i = 0;
	int startIndex = 0, endIndex = 0;

	while (i <= len(string))
	{

		if (string[i] == seperator || i == len(string))
		{
			endIndex = i;
			std::string subStr = "";
			subStr.append(string, startIndex, endIndex - startIndex);
			playerPosString[currIndex] = subStr;
			currIndex += 1;
			startIndex = endIndex + 1;				
		}
		i++;

	}
}

int Game::len(std::string string)
{
	int length = 0;

	for (int i = 0; string[i] != '\0'; i++)
	{
		length++;
	}
	return length;
}




