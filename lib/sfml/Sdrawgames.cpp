//
// EPITECH PROJECT, 2018
// arcade
// File description:
// sfml drawgames
//

#include "SMenu.hpp"

void    SMenu::D_powerUps(int x, int y)
{
	sf::CircleShape pu(5);

	pu.setPosition(x + 9, y + 9);
	pu.setFillColor(sf::Color(225, 225, 216));
	_win->draw(pu);
}

void    SMenu::D_wall(int x, int y)
{
	sf::RectangleShape      wall(sf::Vector2f(25, 25));

	wall.setPosition(x, y);
	wall.setFillColor(sf::Color(149, 158, 4));
	_win->draw(wall);
}

void    SMenu::D_pacR(int x, int y)
{
	sf::CircleShape pac(8);
	sf::Texture     texture;

	texture.loadFromFile("ressources/pacmanR.png");
	pac.setTexture(&texture, false);
	pac.setPosition(x + 6, y + 6);
	_win->draw(pac);
}

void    SMenu::D_pacL(int x, int y)
{
	sf::CircleShape pac(8);
	sf::Texture     texture;

	texture.loadFromFile("ressources/pacmanL.png");
	pac.setTexture(&texture, false);
	pac.setPosition(x + 6, y + 6);
	_win->draw(pac);
}

void    SMenu::D_pacD(int x, int y)
{
	sf::CircleShape pac(8);
	sf::Texture     texture;

	texture.loadFromFile("ressources/pacmanD.png");
	pac.setTexture(&texture, false);
	pac.setPosition(x + 6, y + 6);
	_win->draw(pac);
}

void    SMenu::D_pacU(int x, int y)
{
	sf::CircleShape pac(8);
	sf::Texture     texture;

	texture.loadFromFile("ressources/pacmanU.png");
	pac.setTexture(&texture, false);
	pac.setPosition(x + 6, y + 6);
	_win->draw(pac);
}

void    SMenu::D_ghost(int x, int y)
{
	sf::CircleShape ghost(8);
	sf::Texture     texture;

	texture.loadFromFile("ressources/ghost.png");
	ghost.setTexture(&texture, false);
	ghost.setPosition(x + 6, y + 6);
	//      ghost.setFillColor(sf::Color::Red);
	_win->draw(ghost);
}

void    SMenu::D_ghostE(int x, int y)
{
	sf::CircleShape ghost(8);
	sf::Texture     texture;

	texture.loadFromFile("ressources/ghost_eat.png");
	ghost.setTexture(&texture, false);
	ghost.setPosition(x + 6, y + 6);
	//      ghost.setFillColor(sf::Color::Red);
	_win->draw(ghost);
}

void    SMenu::D_fruit(int x, int y)
{
	sf::CircleShape fruit(2);

	fruit.setPosition(x + 12, y + 12);
	fruit.setFillColor(sf::Color(225, 225, 216));
	_win->draw(fruit);
}

void    SMenu::D_nibblerU(int x, int y)
{
	sf::CircleShape pac(8);
	sf::Texture     texture;

	texture.loadFromFile("ressources/headU.png");
	pac.setTexture(&texture, false);
	pac.setPosition(x + 6, y + 6);
	_win->draw(pac);
}

void    SMenu::D_nibblerD(int x, int y)
{
	sf::CircleShape pac(8);
	sf::Texture     texture;

	texture.loadFromFile("ressources/headD.png");
	pac.setTexture(&texture, false);
	pac.setPosition(x + 6, y + 6);
	_win->draw(pac);
}

void    SMenu::D_nibblerR(int x, int y)
{
	sf::CircleShape pac(8);
	sf::Texture     texture;

	texture.loadFromFile("ressources/headR.png");
	pac.setTexture(&texture, false);
	pac.setPosition(x + 6, y + 6);
	_win->draw(pac);
}

void    SMenu::D_nibblerL(int x, int y)
{
	sf::CircleShape pac(8);
	sf::Texture     texture;

	texture.loadFromFile("ressources/headL.png");
	pac.setTexture(&texture, false);
	pac.setPosition(x + 6, y + 6);
	_win->draw(pac);
}

void    SMenu::D_nibblerF(int x, int y)
{
	sf::CircleShape pac(8);
	sf::Texture     texture;

	texture.loadFromFile("ressources/fruit.png");
	pac.setTexture(&texture, false);
	pac.setPosition(x + 4, y + 4);
	_win->draw(pac);
}

void    SMenu::D_nibblerB(int x, int y)
{
	sf::CircleShape pac(6);
	sf::Texture     texture;

	texture.loadFromFile("ressources/body.png");
	pac.setTexture(&texture, false);	 
        pac.setPosition(x + 6, y + 6);
	_win->draw(pac);
}
