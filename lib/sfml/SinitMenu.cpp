//
// EPITECH PROJECT, 2018
// menu_sf
// File description:
// src
//

#include "SMenu.hpp"

SMenu::SMenu()
	: _menuLib(SFML), _pos(0)
{
	_menuFont.loadFromFile("ressources/CandyColouredClown.otf");
	loadLibs("../../../lib");
	this->loadGames("./games");
	this->init_Info();
	this->init_menu();
}

void	SMenu::init_Info(void)
{
	_menuInfo[0].setFont(_menuFont);
	_menuInfo[0].setColor(sf::Color::Yellow);
	_menuInfo[0].setString("Arcade");
	_menuInfo[0].setPosition(680, 50);
	_menuInfo[0].setCharacterSize(150);
	_menuInfo[1].setFont(_menuFont);
	_menuInfo[1].setColor(sf::Color::White);
	_menuInfo[1].setString("Press N or B to change the Graphic Librarie");
	_menuInfo[1].setPosition(3, 5);
	_menuInfo[1].setCharacterSize(31);
	_menuInfo[2].setFont(_menuFont);
	_menuInfo[2].setColor(sf::Color::White);
	_menuInfo[2].setString("Use UP and DOWN arrows to select");
	_menuInfo[2].setPosition(3, 35);
	_menuInfo[2].setCharacterSize(31);
	_menuInfo[3].setFont(_menuFont);
	_menuInfo[3].setColor(sf::Color::White);
	_menuInfo[3].setString("Press ENTER to confirm");
	_menuInfo[3].setPosition(3, 65);
	_menuInfo[3].setCharacterSize(31);
	_menuInfo[4].setFont(_menuFont);
	_menuInfo[4].setColor(sf::Color::White);
	_menuInfo[4].setString("Press E to exit");
	_menuInfo[4].setPosition(3, 95);
	_menuInfo[4].setCharacterSize(31);
}

void	SMenu::init_menu(void)
{
	_menu[0].setFont(_menuFont);
	_menu[0].setColor(sf::Color::Black);
	_menu[0].setString("Pacman");
	_menu[0].setPosition(750, 400);
	_menu[0].setCharacterSize(100);
	_menu[1].setFont(_menuFont);
	_menu[1].setColor(sf::Color::Black);
	_menu[1].setString("Nibbler");
	_menu[1].setPosition(750, 600);
	_menu[1].setCharacterSize(100);
	_menu[2].setFont(_menuFont);
	_menu[2].setColor(sf::Color::Black);
	_menu[2].setString("Exit");
	_menu[2].setPosition(800, 900);
	_menu[2].setCharacterSize(80);
}

void	SMenu::Up()
{
	if (_pos - 1 >= 0) {
		_pos--;
	}
	else if (_pos == PACMAN) {
		_pos = EXIT;
	}
}

void	SMenu::Down()
{
	if (_pos + 1 < 3) {
		_pos++;
	}
	else if (_pos == EXIT) {
		_pos = PACMAN;
	}
}
