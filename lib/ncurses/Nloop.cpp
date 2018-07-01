//
// EPITECH PROJECT, 2018
// ncurses
// File description:
// src
//

#include "NMenu.hpp"

extern "C" IGraphics* create()
{
	return new NMenu;
}

int		NMenu::menu(void)
{
	int	ch;
	int	return_value = 0;

	initscr();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	this->printAll();
	ch = getch();
	return_value = Kevent(ch);
	if (return_value != 0) {
		endwin();
		return (return_value);
	}
	this->printAll();
	return (0);
}

