/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:44:20 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/11 15:44:24 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	drow_map_body_pers(t_app *app, char c, int j, int i)
{
	if (c == 'P')
	{
		draw_img_at_pos(app, &(app->sp[1]), 48 * j, 48 * i);
		player_position_init(app, j, i);
	}
	else if (c == 'C')
	{
		if (app->flag == 0)
			app->total_col++;
		draw_img_at_pos(app, &(app->sp[1]), 48 * j, 48 * i);
		draw_img_at_pos(app, &(app->sp[2]), 48 * j, 48 * i);
	}
	else if (c == 'E')
	{
		draw_img_at_pos(app, &(app->sp[1]), 48 * j, 48 * i);
		draw_img_at_pos(app, &(app->sp[4]), 48 * j, 48 * i);
	}
}

void	drow_map_body(t_app *app, char c, int j, int i)
{
	if (c == '1')
		draw_img_at_pos(app, &(app->sp[0]), 48 * j, 48 * i);
	else if (c == '0')
		draw_img_at_pos(app, &(app->sp[1]), 48 * j, 48 * i);
	else if (c == 'N')
	{
		draw_img_at_pos(app, &(app->sp[1]), 48 * j, 48 * i);
		draw_img_at_pos(app, &(app->sp[9]), 48 * j, 48 * i);
	}
	else
		drow_map_body_pers(app, c, j, i);
}

void	drow_map(t_app *app)
{
	t_map	*p;
	int		len;
	int		length;
	int		i;
	int		j;

	i = 1;
	p = app->carte;
	length = ft_strlen(p->line);
	len = ft_lstsize(p);
	drow_display(app, length);
	while (i <= len)
	{
		j = 0;
		while (j < (int)ft_strlen(p->line))
		{
			drow_map_body(app, p->line[j], j, i);
			j++;
		}
		p = p->next;
		i++;
	}
	app->flag = 1;
}

void	drow_display(t_app *app, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (i == 0)
			draw_img_at_pos(app, &(app->sp[6]), 48 * i, 0);
		else if (i == length - 1)
			draw_img_at_pos(app, &(app->sp[8]), 48 * i, 0);
		else
			draw_img_at_pos(app, &(app->sp[7]), 48 * i, 0);
		i++;
	}
}
