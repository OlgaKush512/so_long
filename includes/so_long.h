/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:41:02 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/11 15:41:15 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef LINUX
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

# define ALPHA 0xff000000

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

typedef struct s_state
{
	int	player_x;
	int	player_y;
	int	player_old_x;
	int	player_old_y;
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
	t_texture	sp[5];
	char		*path[5];
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

/*srcs/map_init_and_check/read_map*/
t_map	*read_map(const char *filename);
int		is_file(const char *filename);
int		check_filename(const char *filename);

/*srcs/map_init_and_check/fonctions_list*/
t_map	*ft_lstnew(char *line);
t_map	*ft_lstlast(t_map *lst);
void	ft_lstadd_back(t_map **alst, t_map *new);
int		ft_lstsize(t_map *lst);

/*srcs/map_init_and_check/clear_map_list.c*/
void	ft_lstdelone(t_map *lst);
void	ft_lstclear(t_map **lst);

/*srcs/map_init_and_check/check_map.c*/
void	init_check_map(t_check_map *my_check);
int		check_map(t_map *my_map);

/*srcs/map_init_and_check/check_wall_attributs.c*/
int		check_first_last_wall(char *line);
int		check_medium_wall(char *line);
int		check_wall(t_map *my_map);
void	fill_up_attributs(t_map *my_map, t_check_map **my_check);
int		check_attributs(t_map *my_map, t_check_map *my_check);

/*srcs/errors/errors.c*/
void	message_error(int ret);

/*srcs/app_draw_and_action/draw_map.c*/
void	drow_map_body(t_app *app, char c, int j, int i);
void	drow_map(t_app *app);

/*srcs/app_draw_and_action/draw_image.c*/
int		check_pixel(t_texture *txr, int line, int col);
void	draw_img_at_pos_body(t_app *app, t_texture *txr, int st, int bpp);
void	draw_img_at_pos(t_app *app, t_texture *txr, int x, int y);

/*srcs/app_draw_and_action/init.c*/
void	init_path(t_app *app);
void	init_sprite(t_app *app);
void	init_app(t_app *app, char *title, int w, int h);
void	player_position_init(t_app *app, int x, int y);

/*srcs/app_draw_and_action/actions.c*/
int		check_pos_player(t_app *app);
int		change_map(t_app *app, char *pos);
int		player_input(int key, void *data);
int		player_input_body(int key, t_app *app);
int		routine(void *data);

/*srcs/app_draw_and_action/destroying.c*/
int		destroy_game_data(void *data);

#endif
