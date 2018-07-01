//
// EPITECH PROJECT, 2018
// pacman
// File description:
// player
//

#include "Pacman.hpp"

bool	Pacman::checkMove(int y, int x)
{
	if (_map[y][x] == '#')
		return (false);
	return (true);
}

void	Pacman::moveUp()
{
	if (checkMove(_posy - 1, _posx) == true) {
		if (_map[_posy-1][_posx] == '*')
			_score = _score + 10;
		else if (_map[_posy-1][_posx] == '0') {
			_score = _score + 20;
			_takeP = true;
		}
		_map[_posy][_posx] = ' ';
		_map[_posy-1][_posx] = 'v';
		_posy--;
	}
}

void	Pacman::moveDown()
{
	if (checkMove(_posy + 1, _posx) == true) {
		if (_map[_posy+1][_posx] == '*')
			_score = _score + 10;
		else if (_map[_posy+1][_posx] == '0') {
			_score = _score + 20;
			_takeP = true;
		}
		_map[_posy][_posx] = ' ';
		_map[_posy+1][_posx] = 'n';
		_posy++;
	}
}

void	Pacman::moveRight()
{
	if (checkMove(_posy, _posx + 1) == true) {
		if (_posx < 30) {
			if (_map[_posy][_posx+1] == '*')
				_score = _score + 10;
			else if (_map[_posy][_posx+1] == '0') {
				_score = _score + 20;
				_takeP = true;
			}
			_map[_posy][_posx] = ' ';
			_map[_posy][_posx+1] = '{';
			_posx++;
		}
		else {
			if (_map[_posy][0] == '*')
				_score = _score + 10;
			else if (_map[_posy][0] == '0') {
				_score = _score + 20;
				_takeP = true;
			}
			_map[_posy][_posx] = ' ';
			_map[_posy][0] = '{';
			_posx = 0;
		}
	}
}

void	Pacman::moveLeft()
{
	if (checkMove(_posy, _posx - 1) == true) {
		if (_posx > 0) {
			if (_map[_posy][_posx - 1] == '*')
				_score = _score + 10;
			else if (_map[_posy][_posx - 1] == '0') {
				_score = _score + 20;
				_takeP = true;
			}
			_map[_posy][_posx] = ' ';
			_map[_posy][_posx-1] = '}';
			_posx--;
		}
		else {
			if (_map[_posy][30] == '*')
				_score = _score + 10;
			else if (_map[_posy][30] == '0') {
				_score = _score + 20;
				_takeP = true;
			}
			_map[_posy][_posx] = ' ';
			_map[_posy][30] = '}';
			_posx = 30;
		}
	}
}

bool	Pacman::checkTimeG()
{
	std::chrono::time_point<std::chrono::system_clock> endTime;

	endTime = std::chrono::system_clock::now();
	if (std::chrono::duration_cast<std::chrono::milliseconds>(endTime - _startTG).count() >= 10000)
		return (true);
	return (false);
}

bool	Pacman::checkTimeP()
{
	std::chrono::time_point<std::chrono::system_clock> endTime;

	endTime = std::chrono::system_clock::now();
	if (std::chrono::duration_cast<std::chrono::milliseconds>(endTime - _startTP).count() >= 10000)
		return (true);
	return (false);
}

void	Pacman::move(int dir)
{
	if (_launch == false) {
		_startTG = std::chrono::system_clock::now();
		_launch = true;
	}
	else if (checkTimeG() == true)
		moveGhosts();
	switch (dir) {
	case 0:
		if (checkMove(_posy - 1, _posx) == true)
			moveUp();
		break;
	case 1:
		if (checkMove(_posy + 1, _posx) == true)
			moveDown();
		break;
	case 2:
		if (checkMove(_posy, _posx - 1) == true)
			moveLeft();
		break;
	case 3:
		if (checkMove(_posy, _posx + 1) == true)
			moveRight();
		break;
	}
	if (_takeP == true) {
		_startTP = std::chrono::system_clock::now();
		_takeP = false;
		_eat = true;
	}
	if (checkTimeP() == true)
		_eat = false;
}
