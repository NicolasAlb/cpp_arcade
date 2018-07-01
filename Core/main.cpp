//
// EPITECH PROJECT, 2018
// main
// File description:
// src
//

#include "menu_sf.hpp"
#include "NMenu.hpp"
#include "SMenu.hpp"

static void		coreStart(char **av)
{
	Manager		manager(av);

	 while (42) {
		 coreLoop(manager);
	 }
}

int			main(int ac, char **av)
{
	if (ac != 2)
		put_error();
	coreStart(av);
	return (0);
}

