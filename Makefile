##
## EPITECH PROJECT, 2018
## Main Makefile
## File description:
## One Makefile to rule them all
##

CC		= g++

RM		= rm -rf

NAME		= arcade

MAKE	=	make -C

SRCS		= Core/main.cpp \
		  Core/loadLibs.cpp \
		  Core/changeLib.cpp \
		  Core/coreLoop.cpp \
		  Core/error.cpp \
		  Core/Manager.cpp

OBJS		= $(SRCS:.cpp=.o)

CPPFLAGS	+= -W -Werror -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lncurses -I ./include -ldl -std=c++17 -g3

LIB1		= lib_arcade_ncurses.so

LIB2		= lib_arcade_sfml.so

GAME1		= lib_arcade_nibbler.so

GAME2		= lib_arcade_pacman.so

GAME1DIR	= games/nibbler/

GAME2DIR	= games/pacman/

LIB1DIR		= lib/ncurses/

LIB2DIR		= lib/sfml/

all: $(NAME) $(LIB1) $(GAME1) $(GAME2) $(LIB2)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CPPFLAGS)

core:	$(NAME)

games:	$(GAME1) $(GAME2)

graphicals:	$(LIB1) $(LIB2)

$(LIB1):
	$(MAKE) $(LIB2DIR)

$(LIB2):
	$(MAKE) $(LIB1DIR)

$(GAME1):
	$(MAKE) $(GAME1DIR)

$(GAME2):
	$(MAKE) $(GAME2DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIB1) $(GAME1) $(GAME2)
	$(MAKE) $(LIB1DIR) fclean
	$(MAKE) $(LIB2DIR) fclean
	$(MAKE) $(GAME1DIR) fclean
	$(MAKE) $(GAME2DIR) fclean

re: fclean all

.PHONY: all clean fclean re
