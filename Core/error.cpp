//
// EPITECH PROJECT, 2018
// error
// File description:
// src
//

#include "menu_sf.hpp"

void		put_error(void)
{
	std::cerr << "Invalid nb of arguments" << std::endl;
	std::cerr << "Usage:";
	std::cerr << " ./arcade ./lib_arcade_*****.so" << std::endl;
	exit(84);
}

void		lib_error(void)
{
	std::cerr << "Invalid argument" << std::endl;
	std::cerr << "Usage:";
	std::cerr << " ./arcade ./lib_arcade_*****.so" << std::endl;
	std::cerr << "Please replace the * by \"sfml\" or \"ncurses\"" << std::endl;
	exit(84);
}
