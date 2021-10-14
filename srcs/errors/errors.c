/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:42:23 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/11 15:42:26 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	message_error(int ret)
{
	if (ret == 0)
		write(2, "Error\nThe map must be closed/surrounded by walls.\n", 50);
	else if (ret == 2)
		write(2, "Error\nIt must be at least one exit, one collectible.\n", 53);
	else if (ret == 3)
		write(2, "Error\nMap must have one starting position.\n", 43);
	else if (ret == -1)
		write(2, "Error\nThe map must be rectangular.\n", 35);
	else if (ret == 4)
		write(2, "Error\nIt is possible only 5 symbols: 0, 1, C, E, P.\n", 52);
	else if (ret == 5)
		write(2, "Error\nThe map mast have empty space.", 37);
	else if (ret == 6)
		write(2, "Error\nThe file doesn't exist.\n", 30);
	else if (ret == 7)
		write(2, "Error\nThis is a directory!\n", 27);
	else if (ret == 8)
		write(2, "Error\nThe extension is invalid!\n", 32);
	else if (ret == 9)
		write(2, "Error\nUsage: ./so_long [filename]\n", 34);
	else if (ret == 10)
		write(2, "Error\nThe texture doesn't exist\n", 32);
	exit(ret);
}
