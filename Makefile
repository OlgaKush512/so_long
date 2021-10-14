OS		= ${shell uname}

SRCS	=		philo/srcs/main.c philo/srcs/check.c philo/srcs/fonctions_std.c/ philo/srcs/init.c philo/srcs/errors/errors.c			\

SRCS_BONUS	=	

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME			= philo

NAME_BONUS		= pholo_bonus

CC			= gcc -g

CFLAGS		= -Wall -Wextra -Werror -g

RM	= rm -f

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}
bonus : 	${NAME_BONUS}

${NAME_BONUS}:	${OBJS_BONUS}
				${CC} ${CFLAGS} -o ${NAME_BONUS} ${OBJS_BONUS} 

clean:		
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME} ${NAME}_bonus

re:			fclean all

.PHONY:		all mlx clean fclean re bonus
