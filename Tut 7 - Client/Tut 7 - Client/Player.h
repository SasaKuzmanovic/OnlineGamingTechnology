#pragma once

#include <SFML/Graphics.hpp>

class Player {
public:
	

	void render(sf::RenderWindow& t_window);

	void update();
	void init();


	void setID();
	std::string getPlayerPosition()
	{
		return std::to_string(playerBox.getPosition().x) + "," + std::to_string(playerBox.getPosition().y);
	}


	void setPlayerPosition();


	sf::RectangleShape playerBox;

private:
	
};