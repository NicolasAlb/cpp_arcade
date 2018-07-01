//
// EPITECH PROJECT, 2018
// Ndrawmenu
// File description:
// src
//

#include "NMenu.hpp"

void		NMenu::drawMenu()
{
	int	test = 0;

	test = this->getLib();
	if (test == SFML)
		this->menu();
	else if (test == NCURSE)
		this->menu();
}
