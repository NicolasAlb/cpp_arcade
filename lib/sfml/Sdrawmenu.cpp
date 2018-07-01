//
// EPITECH PROJECT, 2018
// SdrawMenu
// File description:
// src
//

#include "SMenu.hpp"

void		SMenu::drawMenu()
{
	int	test = 0;

	test = this->getLib();
	if (test == SFML)
		this->menu();
	else if (test == NCURSE)
		this->menu();
}
