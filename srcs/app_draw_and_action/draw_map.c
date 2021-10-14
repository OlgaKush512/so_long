/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:42:03 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/11 15:42:07 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	drow_map_body(t_app *app, char c, int j, int i)
{
	if (c == '1')
		draw_img_at_pos(app, &(app->sp[0]), 48 * j, 48 * i);
	else if (c == '0')
		draw_img_at_pos(app, &(app->sp[1]), 48 * j, 48 * i);
	else if (c == 'P')
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

void	drow_map(t_app *app)
{
	t_map	*p;
	int		len;
	int		i;
	int		j;

	i = 0;
	p = app->carte;
	len = ft_lstsize(p);
	while (i < len)
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
