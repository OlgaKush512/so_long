OS		= ${shell uname}

SRCS_BONUS	=	srcs_bonus/main_bonus.c tools/get_next_line/get_next_line.c tools/get_next_line/get_next_line_tools.c tools/std_fonctions.c		\
				srcs_bonus/map_init_and_check_bonus/read_map_bonus.c srcs_bonus/map_init_and_check_bonus/fonctions_list_bonus.c 				\
				srcs_bonus/map_init_and_check_bonus/check_map_bonus.c srcs_bonus/map_init_and_check_bonus/check_wall_attributs_bonus.c			\
				srcs_bonus/map_init_and_check_bonus/clear_map_list_bonus.c srcs_bonus/errors_bonus/errors_bonus.c tools/ft_itoa.c				\
				srcs_bonus/app_draw_and_action_bonus/draw_map_bonus.c srcs_bonus/app_draw_and_action_bonus/destroying_bonus.c					\
				srcs_bonus/app_draw_and_action_bonus/init_bonus.c srcs_bonus/app_draw_and_action_bonus/actions_bonus.c 							\
				srcs_bonus/app_draw_and_action_bonus/draw_image_bonus.c																			\


SRCS	=		srcs/main.c tools/get_next_line/get_next_line.c tools/get_next_line/get_next_line_tools.c tools/std_fonctions.c	\
				srcs/map_init_and_check/read_map.c srcs/map_init_and_check/fonctions_list.c 									\
				srcs/map_init_and_check/check_map.c srcs/map_init_and_check/check_wall_attributs.c								\
				srcs/map_init_and_check/clear_map_list.c srcs/errors/errors.c													\
				srcs/app_draw_and_action/draw_map.c srcs/app_draw_and_action/destroying.c										\
				srcs/app_draw_and_action/init.c srcs/app_draw_and_action/actions.c srcs/app_draw_and_action/draw_image.c		\

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME			= so_long

NAME_BONUS		= so_long_bonus

CC			= gcc -g

CFLAGS		= -Wall -Wextra -Werror -g

RM	= rm -f

# mlx library
ifeq ($(OS), Linux)
	MINILIBX = -Lmlx_linux -lmlx_Linux -lXext -lX11
	MLX = @make -C mlx_linux
	INCLUDE_ADD = -D LINUX
else
	MINILIBX = -Lmlx -lmlx -framework OpenGL -framework AppKit
	MLX = @make -C mlx
	INCLUDE_ADD = -D MAC_OS
endif


all: 		mlx ${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INCLUDE_ADD}

mlx :		
			${MLX}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${MINILIBX}

bonus : 	mlx ${NAME_BONUS}

${NAME_BONUS}:	${OBJS_BONUS}
				${CC} ${CFLAGS} -o ${NAME}_bonus ${OBJS_BONUS} ${MINILIBX}

clean:		
			${MLX} clean
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME} ${NAME}_bonus

re:			fclean all

.PHONY:		all mlx clean fclean re
