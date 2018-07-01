//
// EPITECH PROJECT, 2018
// Nprint
// File description:
// src
//

#include "NMenu.hpp"

void		NMenu::printAll()
{
	clear();
	printInfo();
	printArcade();
	printPacman();
	printNibbler();
	printExit();
}

void		NMenu::printInfo()
{
	mvprintw(3, 5, "%s", "Press N or B to change the Graphic Librarie");
	mvprintw(4, 5, "%s", "Available Graphic Libraries : NCURSES // SFML");
	mvprintw(5, 5, "%s", "Use UP and DOWN arrows to select");
	mvprintw(6, 5, "%s", "Press ENTER to confirm");
	mvprintw(7, 5, "%s", "Press E to exit");
	mvprintw(58, 173, "%s", "Made By Sator Adijes");
	mvprintw(59, 173, "%s", "        Nicolas Albanel");
	mvprintw(60, 173, "%s", "        Simon Trousset");
}

void		NMenu::printInfoG()
{
	mvprintw(3, 5, "%s", "Press P or O to change game");
	mvprintw(4, 5, "%s", "Available Games : PACMAN // TETRIS");
	mvprintw(5, 5, "%s", "Press N or B to change the Graphic Librarie");
	mvprintw(6, 5, "%s", "Available Graphic Libraries : NCURSES // SFML");
	mvprintw(7, 5, "%s", "Use arrows KEYS to move");
	mvprintw(8, 5, "%s", "Press R to retry");
	mvprintw(9, 5, "%s", "Press E to exit");
	mvprintw(10, 5, "%s", "Press M to go back to the main menu");
	mvprintw(58, 173, "%s", "Made By Sator Adijes");
	mvprintw(59, 173, "%s", "        Nicolas Albanel");
	mvprintw(60, 173, "%s", "        Simon Trousset");
}

void		NMenu::printInfoGO()
{
	mvprintw(30, 68, "%s", "Press R to retry");
	mvprintw(31, 68, "%s", "Press E to exit");
	mvprintw(32, 68, "%s", "Press M to go back to the main menu");
	mvprintw(33, 68, "%s", "Press N or B to change the Graphic Librarie");
	mvprintw(34, 68, "%s", "Available Graphic Libraries : NCURSES // SFML");
	mvprintw(58, 173, "%s", "Made By Sator Adijes");
	mvprintw(59, 173, "%s", "        Nicolas Albanel");
	mvprintw(60, 173, "%s", "        Simon Trousset");
}
