/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:41:21 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/11 15:41:24 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# if LINUX
#  include "../mlx_linux/mlx.h"
#  define UP 119
#  define DOWN 115
#  define LEFT 97
#  define RIGHT 100
#  define ESC 65307
# elif MAC_OS
#  include "../mlx/mlx.h"
#  define UP 13
#  define DOWN 1
#  define LEFT 0
#  define RIGHT 2
#  define ESC 53
# endif

# include "../tools/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define PATH_TO_WALL "./textures/wall.xpm"
# define PATH_TO_GROUND "./textures/ground1.xpm"
# define PATH_TO_COLLECTIBLE "./textures/collectible.xpm"
# define PATH_TO_PLAYER "./textures/player.xpm"
# define PATH_TO_EXIT   "./textures/exit_map.xpm"
# define PATH_TO_PLAYER_1 "./textures/player1.xpm"
# define PATH_TO_PLAYER_2 "./textures/player2.xpm"
# define PATH_TO_PLAYER_3 "./textures/player3.xpm"
# define PATH_TO_TAB_1 "./textures/tab_1.xpm"
# define PATH_TO_TAB_2 "./textures/tab_2.xpm"
# define PATH_TO_TAB_3 "./textures/tab_3.xpm"
# define PATH_TO_ENEMY "./textures/enemy.xpm"

typedef struct s_state
{
	int	player_x;
	int	player_y;
	int	player_old_x;
	int	player_old_y;
	int	anim;
}				t_state;

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}				t_map;

typedef struct s_check_map
{
	int	trash;
	int	empty_space;
	int	collectible;
	int	exit_map;
	int	start_position;
	int	enemy;
}				t_check_map;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size;
	int		endian;
	int		sp_x;
	int		sp_y;
	t_state	game_state;
}				t_texture;

typedef struct s_app
{
	void		*mlx;
	void		*win;
	void		*image;
	void		*image_addr;
	int			x;
	int			y;
	t_texture	sp[12];
	char		*path[12];
	t_map		*carte;
	int			image_is_destroyed;
	int			nb_mvmt;
	int			total_col;
	int			taken_col;
	int			flag;
}				t_app;

/*tools/std_fonctions.c*/
void	ft_putchar(char c);
void	ft_putnbr( int n);
void	*bit_copy(void *dst, const void *src, int j);
int		is_texture_exist(const char *filename);

/*tools/get_next_line/get_next_line*/
char	*ft_strcpy(char *dst, const char *src);
void	ft_strclr(char *s);
char	*check_ost(char *ost, char **line);
void	make_line(char *ost, char **p_n, char **line, char *buf);
int		get_next_line(int fd, char **line);

/*tools/get_next_line/get_next_line_tools*/
char	*ft_strnew(int count);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);

/*tools/ft_itoa.c*/
int		nb_elem(int n);
char	*make_number(int n, int len, char *str);
char	*ft_itoa(int n);

/*srcs_bonus/map_init_and_check_bonus/read_map_bonus*/
t_map	*read_map(const char *filename);
int		is_file(const char *filename);
int		check_filename(const char *filename);

/*srcs_bonus/map_init_and_check_bonus/fonctions_list_bonus*/
t_map	*ft_lstnew(char *line);
t_map	*ft_lstlast(t_map *lst);
void	ft_lstadd_back(t_map **alst, t_map *new);
int		ft_lstsize(t_map *lst);

/*srcs/map_init_and_check/clear_map_list_bonus.c*/
void	ft_lstdelone(t_map *lst);
void	ft_lstclear(t_map **lst);

/*srcs_bonus/map_init_and_check_bonus/check_map_bonus.c*/
void	init_check_map(t_check_map *my_check);
int		check_map(t_map *my_map);

/*srcs_bonus/map_init_and_check_bonus/check_wall_attributs_bonus.c*/
int		check_first_last_wall(char *line);
int		check_medium_wall(char *line);
int		check_wall(t_map *my_map);
void	fill_up_attributs(t_map *my_map, t_check_map **my_check);
int		check_attributs(t_map *my_map, t_check_map *my_check);

/*srcs_bonus/errors_bonus/errors_bonus.c*/
void	message_error(int ret);

/*srcs_bonus/app_draw_and_action_bonus/draw_map_bonus.c*/
void	drow_map_body_pers(t_app *app, char c, int j, int i);
void	drow_map_body(t_app *app, char c, int j, int i);
void	drow_map(t_app *app);
void	drow_display(t_app *app, int length);

/*srcs_bonus/app_draw_and_action_bonus/draw_image_bonus.c*/
int		check_pixel(t_texture *txr, int line, int col);
void	draw_img_at_pos_body(t_app *app, t_texture *txr, int st, int bpp);
void	draw_img_at_pos(t_app *app, t_texture *txr, int x, int y);

/*srcs_bonus/app_draw_and_action_bonus/init_bonus.c*/
void	init_path(t_app *app);
void	init_sprite(t_app *app);
void	init_app(t_app *app, char *title, int w, int h);
void	animation_player(t_app *app, int x, int y);
void	player_position_init(t_app *app, int x, int y);

/*srcs_bonus/app_draw_and_action_bonus/actions_bonus.c*/
int		check_pos_player(t_app *app);
int		change_map(t_app *app, char *pos);
int		player_input(int key, void *data);
int		player_input_body(int key, t_app *app);
int		routine(void *data);

/*srcs_bonus/app_draw_and_action_bonus/destroying_bonus.c*/
int		destroy_game_data(void *data);

#endif
