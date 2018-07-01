##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for SFML
##

CC	=	g++

RM	=	rm -rf

CPPFLAGS	+=	-W -std=c++17 -Wall -Werror -fPIC -Wextra

CPPFLAGS	+=	-I ../../include

NAME	=	../lib_arcade_sfml.so

SRCS	=	Sdrawmenu.cpp \
		SinitMenu.cpp \
		SKeyboard.cpp \
		SloadLibs.cpp \
		Sloop.cpp \
		Sprint.cpp \
		LSfml.cpp \
		Sgameover.cpp \
		Swin.cpp \
		Sdrawgames.cpp

OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -shared -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
