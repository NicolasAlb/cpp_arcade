//
// EPITECH PROJECT, 2018
// Nascii_art
// File description:
// src
//

#include "NMenu.hpp"

void		NMenu::printArcade()
{
	attron(COLOR_PAIR(2));
	mvprintw(12, 68, "%s", "   _|_|                                        _|     ");       
	mvprintw(13, 68, "%s", " _|    _|  _|  _|_|    _|_|_|    _|_|_|    _|_|_|    _|_|    ");
	mvprintw(14, 68, "%s", " _|_|_|_|  _|_|      _|        _|    _|  _|    _|  _|_|_|_|  ");
	mvprintw(15, 68, "%s", " _|    _|  _|        _|        _|    _|  _|    _|  _|        ");
	mvprintw(16, 68, "%s", " _|    _|  _|          _|_|_|    _|_|_|    _|_|_|    _|_|_|  ");
	attroff(COLOR_PAIR(2));
}

void		NMenu::printPacman()
{
	if (_pos == PACMAN) {
		attron(COLOR_PAIR(3));
		mvprintw(25, 75, "%s", "   ___                                 ");
		mvprintw(26, 75, "%s", "  / _ \\__ _  ___ _ __ ___   __ _ _ __  ");
		mvprintw(27, 75, "%s", " / /_)/ _  |/ __|  _   _ \\ / _  |  _ \\ ");
		mvprintw(28, 75, "%s", "/ ___/ (_| | (__| | | | | | (_| | | | |");
		mvprintw(29, 75, "%s", "\\/    \\__ _|\\___|_| |_| |_|\\__ _|_| |_|");
		attroff(COLOR_PAIR(3));
	} else {
		mvprintw(25, 75, "%s", "   ___                                 ");
		mvprintw(26, 75, "%s", "  / _ \\__ _  ___ _ __ ___   __ _ _ __  ");
		mvprintw(27, 75, "%s", " / /_)/ _  |/ __|  _   _ \\ / _  |  _ \\ ");
		mvprintw(28, 75, "%s", "/ ___/ (_| | (__| | | | | | (_| | | | |");
		mvprintw(29, 75, "%s", "\\/    \\__ _|\\___|_| |_| |_|\\__ _|_| |_|");
	}
}

void		NMenu::printNibbler()
{
	if (_pos == NIBBLER) {
		attron(COLOR_PAIR(4));
		mvprintw(35, 78, "%s", "  _   _ _ _     _     _           ");
		mvprintw(36, 78, "%s", " | \\ | (_) |   | |   | |          ");
		mvprintw(37, 78, "%s", " |  \\| |_| |__ | |__ | | ___ _ __ ");
		mvprintw(38, 78, "%s", " |     | |  _ \\|  _ \\| |/ _ \\  __|");
		mvprintw(39, 78, "%s", " | |\\  | | |_) | |_) | |  __/ |   ");
		mvprintw(40, 78, "%s", " |_| \\_|_|_ __/|_ __/|_|\\___|_|   ");
		attroff(COLOR_PAIR(4));
	} else {
		mvprintw(35, 78, "%s", "  _   _ _ _     _     _           ");
		mvprintw(36, 78, "%s", " | \\ | (_) |   | |   | |          ");
		mvprintw(37, 78, "%s", " |  \\| |_| |__ | |__ | | ___ _ __ ");
		mvprintw(38, 78, "%s", " |     | |  _ \\|  _ \\| |/ _ \\  __|");
		mvprintw(39, 78, "%s", " | |\\  | | |_) | |_) | |  __/ |   ");
		mvprintw(40, 78, "%s", " |_| \\_|_|_ __/|_ __/|_|\\___|_|   ");
	}
}

void		NMenu::printExit()
{
	if (_pos == EXIT) {
		attron(COLOR_PAIR(1));
		mvprintw(50, 83, "%s", " ____  _  _  __  ____ ");
		mvprintw(51, 83, "%s", "(  __)( \\/ )(  )(_  _)");
		mvprintw(52, 83, "%s", " ) _)  )  (  )(   )(  ");
		mvprintw(53, 83, "%s", "(____)(_/\\_)(__) (__) ");
		attroff(COLOR_PAIR(1));
	} else {
		mvprintw(50, 83, "%s", " ____  _  _  __  ____ ");
		mvprintw(51, 83, "%s", "(  __)( \\/ )(  )(_  _)");
		mvprintw(52, 83, "%s", " ) _)  )  (  )(   )(  ");
		mvprintw(53, 83, "%s", "(____)(_/\\_)(__) (__) ");
	}
}

void		NMenu::printGO()
{
	clear();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	mvprintw(12, 68, "%s", "    _____                         ____");
	mvprintw(13, 68, "%s", "   / ____|                       / __ \\");
	mvprintw(14, 68, "%s", "  | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __");
	mvprintw(15, 68, "%s", "  | | |_ |/ _  |  _   _ \\ / _ \\ | |  | \\ \\ / / _ \\  __|");
	mvprintw(16, 68, "%s", "  | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |");
	mvprintw(17, 68, "%s", "   \\_____|\\__ _|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|");
	attroff(COLOR_PAIR(1));
}
