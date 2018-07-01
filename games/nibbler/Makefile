##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

CC	=	g++

RM	=	rm -f

NAME	=	../../games/lib_arcade_nibbler.so

CPPFLAGS	+=	-W -Wall -Werror -Wextra -fPIC -I ../../include

SRCS	=	nibbler.cpp

OBJS	=	$(SRCS:.cpp=.o)

all	:	$(NAME)

$(NAME) :	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) -shared -lsfml-graphics -lsfml-window -lsfml-system

clean :
	$(RM) $(OBJS)

fclean :	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
