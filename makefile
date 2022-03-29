SRC = main.c\
map_management.c\
screen_management.c\
event_management.c\
gameover.c\
ai_management.c\
ai_utils.c\
update.c

OBJ = $(SRC:.c=.o)

NAME = so_long

PRINTF = ft_printf/libftprintf.a

all		:	$(NAME)

$(PRINTF):
	make -C ft_printf

$(NAME)	:	$(OBJ) $(PRINTF)
	gcc $(OBJ) -Lmlx -lmlx -lm -g -framework OpenGL -framework AppKit -o $(NAME) $(PRINTF)

%.o		:	%.c
	gcc -Wall -Werror -Wextra -Imlx -g -c $< -o $@

clean	:
	rm -f $(OBJ)
	make clean -C ft_printf

fclean	:	clean
	rm -f $(NAME)
	make fclean -C ft_printf

re		:	fclean all
