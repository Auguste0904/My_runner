##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Creation of makefile
##

SRC	=	src/help.c		\
		src/my_putchar.c	\
		src/my_putstr.c		\
		src/my_strcmp.c		\
		src/main.c		\
		src/menu.c		\
		src/create_all.c	\
		src/move_chara.c	\
		src/move_para.c		\
		src/all_destroy.c	\
		src/draw.c		\
		src/create_texture.c	\
		src/my_itoa.c		\
		src/my_runner.c		\
		src/end_menu.c		\
		src/event_close.c

CC	=	gcc

CFLAGS	=	-Wall -Wextra -g

LFLAGS	=	-lcsfml-window -lcsfml-system -lcsfml-audio \
	-lcsfml-graphics -lm

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJ)

debug:
	$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)
	rm -f *.gcno *.gcda *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all debug clean fclean re
