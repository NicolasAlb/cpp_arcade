//
// EPITECH PROJECT, 2018
// NinitMenu
// File description:
// src
//

#include "NMenu.hpp"

NMenu::NMenu()
	: _menuLib(NCURSE), _pos(0)
{
	_win = initscr();
	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	loadLibs("./lib");
	this->loadGames("./games");
}

void	NMenu::Up()
{
	if (_pos - 1 >= 0) {
		_pos--;
	}
	else if (_pos == PACMAN) {
		_pos = EXIT;
	}
}

void	NMenu::Down()
{
	if (_pos + 1 < 3) {
		_pos++;
	}
	else if (_pos == EXIT) {
		_pos = PACMAN;
	}
}
