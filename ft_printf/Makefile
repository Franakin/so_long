SRCS = \
ft_printf.c\
convert_du.c\
convert_x.c\

OBJS = ${SRCS:.c=.o}

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all	:	${NAME}

$(LIBFT):
	make -C libft

test	:
	make all
	gcc ${FLAGS} ${NAME}

${NAME}	:	${OBJS} $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar -rcsu ${NAME} ${OBJS} 

clean	:
	make clean -C libft
	rm -f ${OBJS}

fclean	:	clean
	make fclean -C libft
	rm -f ${NAME}

re	: fclean all
