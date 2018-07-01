//
// EPITECH PROJECT, 2018
// NloadLibs
// File description:
// src
//

#include "NMenu.hpp"

void				NMenu::loadLibs(std::string path)
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
}

void				NMenu::loadGames(std::string path)
{
  DIR				*DIR;
  struct dirent			*dirent;
  std::string			tmp;

  if ((DIR = opendir(path.c_str()))) {
	  while ((dirent = readdir(DIR))) {
		  tmp = dirent->d_name;
		  if (tmp.find("lib_arcade_") == 0 && tmp.find(".so") == tmp.size() - 3)
			  _game_list.push_back(path + "/" + tmp);
	  }
	  closedir(DIR);
  }
}
