//
// EPITECH PROJECT, 2018
// arcade
// File description:
// ghosts pacman
//

#include "Pacman.hpp"

int	Pacman::checkFruit(int y, int x)
{
	if (_map[y][x] == '*')
		return (1);
	else if (_map[y][x] == '0')
		return (2);
	return (0);
}

bool	Pacman::checkGhost(int y, int x)
{
	if (_map[y][x] == '6')
		return (false);
	return (true);
}

void	Pacman::GUp(int a)
{
	if (checkMove(_posG[a][0] - 1, _posG[a][1]) && checkGhost(_posG[a][0] - 1, _posG[a][1])) {
		if (_posG[a][2] == 0)
			_map[_posG[a][0]][_posG[a][1]] = ' ';
		else if (_posG[a][2] == 1)
			_map[_posG[a][0]][_posG[a][1]] = '*';
		else
			_map[_posG[a][0]][_posG[a][1]] = '0';
		_posG[a][2] = checkFruit(_posG[a][0] - 1, _posG[a][1]);
		_map[_posG[a][0]-1][_posG[a][1]] = '6';
		_posG[a][0]--;
	}
}

void	Pacman::GDown(int a)
{
	if (checkMove(_posG[a][0] + 1, _posG[a][1]) && checkGhost(_posG[a][0] + 1, _posG[a][1])) {
		if (_posG[a][2] == 0)
			_map[_posG[a][0]][_posG[a][1]] = ' ';
		else if (_posG[a][2] == 1)
			_map[_posG[a][0]][_posG[a][1]] = '*';
		else
			_map[_posG[a][0]][_posG[a][1]] = '0';
		_posG[a][2] = checkFruit(_posG[a][0] + 1, _posG[a][1]);
		_map[_posG[a][0]+1][_posG[a][1]] = '6';
		_posG[a][0]++;
	}
}

void	Pacman::GRight(int a)
{
	if (checkMove(_posG[a][0], _posG[a][1] + 1) && checkGhost(_posG[a][0], _posG[a][1] + 1)) {
		if (_posG[a][2] == 0)
			_map[_posG[a][0]][_posG[a][1]] = ' ';
		else if (_posG[a][2] == 1)
			_map[_posG[a][0]][_posG[a][1]] = '*';
		else
			_map[_posG[a][0]][_posG[a][1]] = '0';
		if (_posG[a][1] < 30) {
			_posG[a][2] = checkFruit(_posG[a][0], _posG[a][1] + 1);
			_map[_posG[a][0]][_posG[a][1]+1] = '6';
			_posG[a][1]++;
		}
		else {
			_posG[a][2] = checkFruit(_posG[a][0], 0);
			_map[_posG[a][0]][0] = '6';
			_posG[a][1] = 0;
		}
	}
}

void	Pacman::GLeft(int a)
{
	if (checkMove(_posG[a][0], _posG[a][1] - 1) && checkGhost(_posG[a][0], _posG[a][1] - 1)) {
		if (_posG[a][2] == 0)
			_map[_posG[a][0]][_posG[a][1]] = ' ';
		else if (_posG[a][2] == 1)
			_map[_posG[a][0]][_posG[a][1]] = '*';
		else
			_map[_posG[a][0]][_posG[a][1]] = '0';
		if (_posG[a][1] > 0) {
			_posG[a][2] = checkFruit(_posG[a][0], _posG[a][1] - 1);
			_map[_posG[a][0]][_posG[a][1]-1] = '6';
			_posG[a][1]--;
		}
		else {
			_posG[a][2] = checkFruit(_posG[a][0], 30);
			_map[_posG[a][0]][30] = '6';
			_posG[a][1] = 30;
		}
	}
}

void	Pacman::moveIa(int g)
{
	int	i = rand() % 2;

	if (i == 0) {
		if (_posy < _posG[g][0])
			GUp(g);
		else if (_posy > _posG[g][0])
			GDown(g);
	}
	else {
		if (_posx > _posG[g][1])
			GRight(g);
		else if (_posx < _posG[g][1])
			GLeft(g);
	}
}

void	Pacman::moveRandom(int g)
{
	int	i = rand() % 4;

	switch (i) {
	case 0:
		GDown(g);
		break;
	case 1:
		GLeft(g);
		break;
	case 2:
		GRight(g);
		break;
	case 3:
		GUp(g);
		break;
	}
}

void	Pacman::runAway(int g)
{
        int     i = rand() % 2;

	if (i == 0) {
		if (_posy > _posG[g][0])
			GUp(g);
		else if (_posy < _posG[g][0])
			GDown(g);
	}
	else {
		if (_posx < _posG[g][1])
			GRight(g);
		else if (_posx > _posG[g][1])
			GLeft(g);
	}
	
}

void	Pacman::moveGhosts()
{
	int	g;
	int	i;

	for (g = 0; g < 3; g++) {
		if (_eat == false) {
			i = rand() % 5;
			if (i == 0)
				moveRandom(g);
			else
				moveIa(g);
		}
		else
			runAway(g);		
	}
	checkGhosts();
}

void	Pacman::checkGhosts()
{
	int	i;

	for (i = 0; i < 3; i++) {
		if (_posG[i][0] == _posy && _posG[i][1] == _posx) {
			if (_eat == true) {
				_score = _score + 200;
				_map[13][15] = '6';
				_posG[i][0] = 13;
				_posG[i][1] = 15;
				_posG[i][2] = 0;
			}
			else
				_end = true;
		}
	}
}
