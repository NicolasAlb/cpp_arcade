//
// EPITECH PROJECT, 2018
// Nd_nibbler
// File description:
// src
//

#include "NMenu.hpp"

void	NMenu::D_nibblerL(int x, int y)
{
	mvprintw(y, x, "<");
	refresh();
}

void	NMenu::D_nibblerU(int x, int y)
{
	mvprintw(y, x, "^");
	refresh();
}

void	NMenu::D_nibblerR(int x, int y)
{
	mvprintw(y, x, ">");
	refresh();
}

void	NMenu::D_nibblerD(int x, int y)
{
	mvprintw(y, x, "y");
	refresh();
}

void	NMenu::D_nibblerB(int x, int y)
{
	mvprintw(y, x, "o");
	refresh();
}

void	NMenu::D_nibblerF(int x, int y)
{
	mvprintw(y, x, "f");
	refresh();
}
