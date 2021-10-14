/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:44:39 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/11 15:44:41 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	init_path(t_app *app)
{
	if (is_texture_exist(PATH_TO_WALL))
		app->path[0] = PATH_TO_WALL;
	if (is_texture_exist(PATH_TO_GROUND))
		app->path[1] = PATH_TO_GROUND;
	if (is_texture_exist(PATH_TO_COLLECTIBLE))
		app->path[2] = PATH_TO_COLLECTIBLE;
	if (is_texture_exist(PATH_TO_PLAYER))
		app->path[3] = PATH_TO_PLAYER;
	if (is_texture_exist(PATH_TO_EXIT))
		app->path[4] = PATH_TO_EXIT;
	if (is_texture_exist(PATH_TO_PLAYER_1))
		app->path[5] = PATH_TO_PLAYER_1;
	if (is_texture_exist(PATH_TO_TAB_1))
		app->path[6] = PATH_TO_TAB_1;
	if (is_texture_exist(PATH_TO_TAB_2))
		app->path[7] = PATH_TO_TAB_2;
	if (is_texture_exist(PATH_TO_TAB_3))
		app->path[8] = PATH_TO_TAB_3;
	if (is_texture_exist(PATH_TO_ENEMY))
		app->path[9] = PATH_TO_ENEMY;
	if (is_texture_exist(PATH_TO_PLAYER_2))
		app->path[10] = PATH_TO_PLAYER_2;
	if (is_texture_exist(PATH_TO_PLAYER_3))
		app->path[11] = PATH_TO_PLAYER_3;
}

void	init_sprite(t_app *app)
{
	int			i;
	t_texture	*spt;
	char		**m_path;

	i = 0;
	spt = app->sp;
	m_path = app->path;
	while (i < 12)
	{
		spt[i].img = mlx_xpm_file_to_image(app->mlx, m_path[i],
				&spt[i].sp_x, &spt[i].sp_y);
		spt[i].addr = mlx_get_data_addr(spt[i].img, &(spt[i].bpp),
				&(spt[i].size), &(spt[i].endian));
		i++;
	}
}

void	init_app(t_app *app, char *title, int w, int h)
{
	app->mlx = mlx_init();
	if (app->mlx == NULL)
		exit (1);
	init_path(app);
	init_sprite(app);
	app->x = w * app->sp[0].sp_x;
	app->y = (h + 1) * app->sp[0].sp_y;
	app->win = mlx_new_window(app->mlx, app->x, app->y, title);
	if (app->win == NULL)
	{
		free(app->mlx);
		exit (1);
	}
	app->sp[3].game_state.player_x = 0;
	app->sp[3].game_state.player_y = 0;
	app->sp[3].game_state.player_old_x = 0;
	app->sp[3].game_state.player_old_y = 0;
	app->image_is_destroyed = 0;
	app->total_col = 0;
	app->taken_col = 0;
	app->flag = 0;
	app->sp[3].game_state.anim = 0;
	app->nb_mvmt = 0;
}

void	animation_player(t_app *app, int x, int y)
{
	int	nbr_mouv;

	nbr_mouv = app->sp[3].game_state.anim;
	app->sp[3].game_state.anim++;
	if (nbr_mouv < 30)
		draw_img_at_pos(app, &(app->sp[3]), 48 * x, 48 * y);
	else if (nbr_mouv >= 30 && nbr_mouv < 60)
		draw_img_at_pos(app, &(app->sp[5]), 48 * x, 48 * y);
	else if (nbr_mouv >= 60 && nbr_mouv < 90)
		draw_img_at_pos(app, &(app->sp[10]), 48 * x, 48 * y);
	else if (nbr_mouv >= 90 && nbr_mouv < 120)
		draw_img_at_pos(app, &(app->sp[11]), 48 * x, 48 * y);
	if (app->sp[3].game_state.anim == 120)
		app->sp[3].game_state.anim = 0;
}

void	player_position_init(t_app *app, int x, int y)
{
	if (app->sp[3].game_state.player_x == 0
		&& app->sp[3].game_state.player_y == 0)
	{
		app->sp[3].game_state.player_x = x;
		app->sp[3].game_state.player_y = y;
		app->sp[3].game_state.player_old_x = x;
		app->sp[3].game_state.player_old_y = y;
	}	
}
