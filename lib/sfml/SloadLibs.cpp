//
// EPITECH PROJECT, 2018
// SloadLibs
// File description:
// src
//

#include "SMenu.hpp"

void				SMenu::loadLibs(std::string path)
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

void				SMenu::loadGames(std::string path)
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
