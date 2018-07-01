//
// EPITECH PROJECT, 2018
// arcade
// File description:
// ncurse
//

#include <unistd.h>
#include "NMenu.hpp"

void    NMenu::setMap(const std::vector<std::string> map)
{
	_map = map;
}

void    NMenu::drawMap()
{
	std::vector<std::string>::iterator      it = _map.begin();
	int                                     x, y = 20;
	int					i = 0;
	while (it != _map.end()) {
		while ((*it)[i] != '\0') {
			(this->*this->draw_func[(*it)[i]])(x++, y);
			i++;
		}
		x = 80;
		i = 0;
		y++;
		it++;
	}
	printInfoG();
}

void	NMenu::D_wall(int x, int y)
{
	mvprintw(y, x, "#");
	refresh();
}

void	NMenu::D_fruit(int x, int y)
{
	mvprintw(y, x, "*");
	refresh();
}

void	NMenu::D_space(int x, int y)
{
	mvprintw(y, x, " ");
	refresh();
}


void	NMenu::D_ghost(int x, int y)
{
	mvprintw(y, x, "6");
	refresh();
}

void	NMenu::D_powerUps(int x, int y)
{
	mvprintw(y, x, "6");
	refresh();
}

int	NMenu::draw(IGame *pac)
{
	int	c;

	draw_func['<'] = &NMenu::D_nibblerL;
	draw_func['>'] = &NMenu::D_nibblerR;
	draw_func['^'] = &NMenu::D_nibblerU;
	draw_func['v'] = &NMenu::D_nibblerD;
	draw_func['o'] = &NMenu::D_nibblerB;
	draw_func['*'] = &NMenu::D_fruit;
	draw_func['#'] = &NMenu::D_wall;
	draw_func[' '] = &NMenu::D_space;
	draw_func['y'] = &NMenu::D_pacU;
	draw_func['{'] = &NMenu::D_pacR;
	draw_func['}'] = &NMenu::D_pacL;
	draw_func['n'] = &NMenu::D_pacD;
	draw_func['6'] = &NMenu::D_ghost;
	draw_func['0'] = &NMenu::D_powerUps;
	draw_func['f'] = &NMenu::D_nibblerF;
	curs_set(0);
	start_color();
	setMap(pac->getMap());
	drawMap();
	refresh();
	nodelay(stdscr, true);
	_dir = RIGHT;
	while (42) {
		c = getch();
		switch (c) {
		case KEY_UP:
			_dir = UP;
			break;
		case KEY_DOWN:
			_dir = DOWN;
			break;
		case KEY_LEFT:
			_dir = LEFT;
			break;
		case KEY_RIGHT:
			_dir = RIGHT;
			break;
		case 114:
			return (RES_PAC);
			break;
		case 101:
			endwin();
			exit(0);
			break;
		case 98:
			endwin();
			return (CHANGE_LIB);
			break;
		case 109:
			return (BACK_MENU);
			break;
		case 110:
			endwin();
			return (CHANGE_LIB);
			break;
		case 111:
			return (CHANGE_G);
			break;
		case 112:
			return (CHANGE_G);
			break;
		}
		pac->move(_dir);
		clear();
		setMap(pac->getMap());
		drawMap();
		refresh();
		if (pac->getEnd() == true) {
			endwin();
			return (gameOver());
		}
		usleep(100000);
	}
	endwin();
	return (0);
}
