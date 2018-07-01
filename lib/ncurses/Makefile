##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for NCURSE
##

CC	=	g++

RM	=	rm -rf

CPPFLAGS	+=	-W -std=c++17 -Wall -Werror -fPIC -Wextra

CPPFLAGS	+=	-I ../../include

NAME	=	../lib_arcade_ncurses.so

SRCS	=	Nascii_art.cpp \
		Ndrawmenu.cpp \
		NinitMenu.cpp \
		NKeyboard.cpp \
		NloadLibs.cpp \
		Nloop.cpp \
		Nprint.cpp \
		Nd_pac.cpp \
		Nd_nibbler.cpp \
		LNcurses.cpp \
		Ngameover.cpp

OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -shared -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
