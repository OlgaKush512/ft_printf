
SRCS	=		ft_printf.c fonctions.c spec.c std_fonctions.c

BONUS_SRCS =	ft_printf_bonus.c fonctions_bonus.c spec_bonus.c std_fonctions_bonus.c				\
				spec_c_perc_bonus.c spec_s_bonus.c spec_int_bonus.c spec_p_alignements_i_bonus.c

OBJS	= ${SRCS:.c=.o}

BONUS_OBJ	= ${BONUS_SRCS:.c=.o}

NAME	= libftprintf.a

CC 	= gcc

RM	= rm -f

CFLAGS	=  -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

bonus:		${BONUS_OBJ}
			ar rcs ${NAME} ${BONUS_OBJ}
			ranlib ${NAME}

clean:		
			${RM} ${OBJS} ${BONUS_OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re