//
// EPITECH PROJECT, 2018
// Nd_pac
// File description:
// src
//

#include "NMenu.hpp"

void	NMenu::D_pacR(int x, int y)
{
	mvprintw(y, x, "{");
	refresh();
}

void	NMenu::D_pacL(int x, int y)
{
	mvprintw(y, x, "}");
	refresh();
}

void	NMenu::D_pacD(int x, int y)
{
	mvprintw(y, x, "n");
	refresh();
}

void	NMenu::D_pacU(int x, int y)
{
	mvprintw(y, x, "y");
	refresh();
}
