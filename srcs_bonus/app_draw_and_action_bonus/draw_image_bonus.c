/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <okushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:12:03 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/12 15:12:06 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	check_pixel(t_texture *txr, int line, int col)
{
	int	bpp;

	bpp = txr->bpp / 8;
	if ((txr->addr[line * txr->size + col * bpp + 0] != 0)
		&& (txr->addr[line * txr->size + col * bpp + 1] != 0)
		&& (txr->addr[line * txr->size + col * bpp + 2] != 0)
		&& (txr->addr[line * txr->size + col * bpp + 3] != -1))
		return (1);
	else
		return (0);
}

void	draw_img_at_pos_body(t_app *app, t_texture *txr, int st, int bpp)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < txr->sp_y)
	{
		j = 0;
		while (j < txr->sp_y)
		{
			if (check_pixel(txr, i, j))
			{
				k = 0;
				while (k < 3)
					bit_copy(app->image_addr + st + i * app->x * bpp + j * bpp,
						txr->addr + bpp * txr->sp_x * i + j * bpp, k++);
			}
			j++;
		}
		i++;
	}
}

void	draw_img_at_pos(t_app *app, t_texture *txr, int x, int y)
{
	int	st;
	int	bpp;

	bpp = txr->bpp / 8;
	st = (txr->bpp / 8) * (x + y * app->x);
	draw_img_at_pos_body(app, txr, st, bpp);
}
