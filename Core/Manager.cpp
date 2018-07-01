//
// EPITECH PROJECT, 2018
// Manager
// File description:
// src
//

#include "menu_sf.hpp"

Manager::Manager(char **av)
	: lib(0)
{
	this->loadLibs("./lib");
	this->update_lib(av[1]);
	this->loadLib(this->_lib_list[lib]);
}


