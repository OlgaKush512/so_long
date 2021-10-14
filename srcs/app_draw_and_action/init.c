/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:42:12 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/11 15:42:14 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
}

void	init_sprite(t_app *app)
{
	int			i;
	t_texture	*spt;
	char		**m_path;

	i = 0;
	spt = app->sp;
	m_path = app->path;
	while (i < 5)
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
	app->y = h * app->sp[0].sp_y;
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
	app->nb_mvmt = 0;
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
