##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for Pacman
##

CC	=	g++

RM	=	rm -rf

CPPFLAGS	+=	-W -std=c++17 -Wall -Werror -fPIC -Wextra

CPPFLAGS	+=	-I ../../include

NAME	=	../../games/lib_arcade_pacman.so

SRCS	=	Ghosts.cpp \
		Pacman.cpp \
		Player.cpp

OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -shared -lsfml-graphics -lsfml-window -lsfml-system

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
