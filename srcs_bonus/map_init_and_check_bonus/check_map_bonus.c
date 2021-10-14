/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:45:16 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/11 15:45:18 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	init_check_map(t_check_map *my_check)
{
	my_check->trash = 0;
	my_check->empty_space = 0;
	my_check->collectible = 0;
	my_check->exit_map = 0;
	my_check->start_position = 0;
	my_check->enemy = 0;
}

int	check_map(t_map *my_map)
{
	t_check_map	my_check;
	int			ret;

	ret = check_wall(my_map);
	if (ret == 1)
	{
		init_check_map(&my_check);
		ret = check_attributs(my_map, &my_check);
	}
	return (ret);
}
