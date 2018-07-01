//
// EPITECH PROJECT, 2018
// printMenu
// File description:
// src
//

#include "SMenu.hpp"

void	SMenu::printAll(sf::RenderWindow &w)
{
	sf::RectangleShape	color(sf::Vector2f(1820, 980));
	sf::RectangleShape	back(sf::Vector2f(1920, 1080));
	sf::Text		info;
	sf::Text		info2;
	sf::Text		info3;
	sf::Text		info4;
	sf::Text		info5;
	sf::Text		info6;
	sf::Font		font;

	font.loadFromFile("ressources/CandyColouredClown.otf");
	info.setFont(font);
	info.setString("AVAILABLE GAMES");
	info.setCharacterSize(34);
	info.setPosition(30, 900);
	info.setColor(sf::Color::White);
	info2.setFont(font);
	info2.setString("PACMAN");
	info2.setCharacterSize(34);
	info2.setPosition(30, 960);
	info2.setColor(sf::Color::White);
	info3.setFont(font);
	info3.setString("NIBBLER");
	info3.setCharacterSize(34);
	info3.setPosition(30, 1010);
	info3.setColor(sf::Color::White);
	info4.setFont(font);
	info4.setString("AVAILABLE LIB");
	info4.setCharacterSize(34);
	info4.setPosition(1600, 900);
	info4.setColor(sf::Color::White);
	info5.setFont(font);
	info5.setString("NCURSES");
	info5.setCharacterSize(34);
	info5.setPosition(1600, 960);
	info5.setColor(sf::Color::White);
	info6.setFont(font);
	info6.setString("SFML");
	info6.setCharacterSize(34);
	info6.setPosition(1600, 1010);
	info6.setColor(sf::Color::White);
	color.setPosition(50, 50);
	color.setFillColor(sf::Color::Transparent);
	back.setFillColor(sf::Color::Black);
	w.clear(sf::Color(255, 255, 255));
	w.draw(back);
	w.draw(color);
	w.draw(info);
	w.draw(info2);
	w.draw(info3);
	w.draw(info4);
	w.draw(info5);
	w.draw(info6);
	for (int i = 0; i != 5; i++) {
		w.draw(_menuInfo[i]);
	}
	printPacman(w);
	printNibbler(w);
	printExit(w);
	w.display();
}

void	SMenu::printPacman(sf::RenderWindow &w)
{
	if (_pos == PACMAN) {
		_menu[0].setColor(sf::Color::Blue);
	}
	else {
		_menu[0].setColor(sf::Color::White);
	}
	w.draw(_menu[0]);
}

void	SMenu::printNibbler(sf::RenderWindow &w)
{
	if (_pos == NIBBLER) {
		_menu[1].setColor(sf::Color::Green);
	}
	else {
		_menu[1].setColor(sf::Color::White);
	}
	w.draw(_menu[1]);
}

void	SMenu::printExit(sf::RenderWindow &w)
{
	if (_pos == EXIT) {
		_menu[2].setColor(sf::Color::Red);
	}
	else {
		_menu[2].setColor(sf::Color::White);
	}
	w.draw(_menu[2]);
}
