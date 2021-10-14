/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroying.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:41:56 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/11 15:41:59 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	destroy_game_data(void *data)
{
	t_app		*app;
	int			i;
	t_texture	*spt;

	app = (t_app *)data;
	i = 0;
	spt = app->sp;
	while (i < 5)
	{
		mlx_destroy_image(app->mlx, spt[i].img);
		i++;
	}
	if (app->image_is_destroyed == 0)
		mlx_destroy_image(app->mlx, app->image);
	mlx_clear_window(app->mlx, app->win);
	mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	ft_lstclear(&(app->carte));
	free(app->carte);
	exit (0);
}
