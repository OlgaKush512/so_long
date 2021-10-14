/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:44:06 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/11 15:44:09 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	check_pos_player(t_app *app)
{
	t_map	*p;
	int		len;
	int		str_len;
	int		i;

	i = 1;
	p = app->carte;
	len = app->sp[3].game_state.player_y;
	str_len = app->sp[3].game_state.player_x;
	while (i < len)
	{
		p = p->next;
		i++;
	}
	if (p->line[str_len] == '1')
	{
		app->sp[3].game_state.player_x = app->sp[3].game_state.player_old_x;
		app->sp[3].game_state.player_y = app->sp[3].game_state.player_old_y;
		return (0);
	}
	else if (p->line[str_len] == 'C' || p->line[str_len] == 'E'
		|| p->line[str_len] == 'N')
		return (change_map(app, &(p->line[str_len])));
	return (1);
}

int	change_map(t_app *app, char *pos)
{
	if (*pos == 'C')
	{
		*pos = '0';
		app->taken_col++;
	}
	else if (*pos == 'E')
	{
		if (app->taken_col != app->total_col)
		{
			app->sp[3].game_state.player_x = app->sp[3].game_state.player_old_x;
			app->sp[3].game_state.player_y = app->sp[3].game_state.player_old_y;
			return (0);
		}
		else
			destroy_game_data(app);
	}
	else if (*pos == 'N')
		destroy_game_data(app);
	return (1);
}

int	player_input(int key, void *data)
{
	t_app	*app;
	int		x;
	int		y;

	app = (t_app *)(data);
	x = app->sp[3].game_state.player_x;
	y = app->sp[3].game_state.player_y;
	app->sp[3].game_state.player_old_x = x;
	app->sp[3].game_state.player_old_y = y;
	return (player_input_body(key, app));
}

int	player_input_body(int key, t_app *app)
{
	if (key == LEFT || key == RIGHT || key == DOWN || key == UP)
	{
		if (key == LEFT)
			app->sp[3].game_state.player_x += -1;
		else if (key == RIGHT)
			app->sp[3].game_state.player_x += 1;
		else if (key == DOWN)
			app->sp[3].game_state.player_y += 1;
		else if (key == UP)
			app->sp[3].game_state.player_y += -1;
		if (check_pos_player(app))
			app->nb_mvmt++;
	}
	if (key == ESC)
		destroy_game_data(app);
	return (1);
}

int	routine(void *data)
{
	t_app		*app;
	int			x;
	int			y;
	int			discard;
	char		*nbr;

	app = (t_app *)(data);
	app->image = mlx_new_image(app->mlx, app->x, app->y);
	app->image_addr = mlx_get_data_addr(app->image,
			&discard, &discard, &discard);
	app->image_is_destroyed = 0;
	drow_map(app);
	x = app->sp[3].game_state.player_x;
	y = app->sp[3].game_state.player_y;
	animation_player(app, x, y);
	mlx_put_image_to_window(app->mlx, app->win, app->image, 0, 0);
	mlx_string_put(app->mlx, app->win, 15, 20, 0xFFFFFF,
		"current number of movements: ");
	nbr = ft_itoa(app->nb_mvmt);
	mlx_string_put(app->mlx, app->win, 220, 20, 0xFFFFFF, nbr);
	mlx_destroy_image(app->mlx, app->image);
	free(nbr);
	app->image = NULL;
	app->image_is_destroyed = 1;
	return (0);
}
