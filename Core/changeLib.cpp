//
// EPITECH PROJECT, 2018
// changeLib
// File description:
// src
//

#include "NMenu.hpp"
#include "SMenu.hpp"
#include "menu_sf.hpp"

void		Manager::changeLib()
{
	if (this->current_lib == L_SF) {
		this->current_lib = L_NC;
		this->lib = 1;
		this->loadLib(this->_lib_list[this->lib]);
	}
	else if (this->current_lib == L_NC) {
		this->current_lib = L_SF;
		this->lib = 0;
		this->loadLib(this->_lib_list[this->lib]);
	}
}

void		Manager::update_lib(std::string lib)
{
	std::unordered_map<std::string, LIBS> mapLib = {{"lib_arcade_sfml.so", L_SF},
							{"lib_arcade_ncurses.so", L_NC}}; 

	for (auto &it : mapLib)
		if (it.first == lib)
		{
			current_lib = it.second;
			this->lib = it.second;
		}		
}
