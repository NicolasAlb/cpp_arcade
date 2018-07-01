//
// EPITECH PROJECT, 2018
// loadLibs
// File description:
// src
//

#include "menu_sf.hpp"

void			Manager::loadLib(std::string lib)
{
	void			*handle;
	IGraphics		*(*create)(void);

	handle = dlopen(lib.c_str(), RTLD_LAZY);
	if (handle == nullptr) {
		std::cout << dlerror() << std::endl;
		std::cerr << "Invalid Lib" << std::endl;
		exit(84);
	}
	create = (IGraphics*(*)(void))dlsym(handle, "create");
	if (create == nullptr) {
		std::cerr << "Invalid Lib BITCH" << std::endl;
		exit(84);
	}
	_lib = create();
}

void			Manager::loadGame(std::string game)
{
	void			*handle;
	IGame			*(*create)(void);

	handle = dlopen(game.c_str(), RTLD_LAZY);
	if (handle == NULL) {
		std::cout << dlerror() << std::endl;
		std::cerr << "Invalid Game" << std::endl;
		exit(84);
	}
	create = (IGame*(*)(void))dlsym(handle, "create");
	if (create == NULL) {
		std::cerr << "Invalid Game BITCH" << std::endl;
		exit(84);
	}
	_game = create();
}

void				Manager::loadLibs(std::string path)
{
	DIR				*DIR;
	struct dirent			*dirent;
	std::string			tmp;

	if ((DIR = opendir(path.c_str()))) {
		while ((dirent = readdir(DIR))) {
			tmp = dirent->d_name;
			if (tmp.find("lib_arcade_") == 0 && tmp.find(".so") == tmp.size() - 3)
				_lib_list.push_back(path + "/" + tmp);
		}
		closedir(DIR);
	}
	if (_lib_list.size() == 0) {
		std::cerr << "No graphics lib found" << std::endl;
		exit(84);
	}
}

