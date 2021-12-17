SRC = ./ft_printf.c ./ft_putchar.c ./ft_putstr.c ./ft_putnbr.c ./ft_putvoid.c ./ft_puthexa.c

OBJ = ${SRC:.c=.o}

NAME = libftprintf.a

HEAD = includes

GCC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar rcs

RANLIB = ranlib

.c.o:
		${GCC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${HEAD}

${NAME}:${OBJ}
		${AR} ${NAME} ${OBJ}
		${RANLIB} ${NAME}

all: 	${NAME}

clean: 
		${RM} ${OBJ}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

norm:
		norminette -R CheckForbiddenSourceHeader *.c
		norminette -R CheckDefine *.h
