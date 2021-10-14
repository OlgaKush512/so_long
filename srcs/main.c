/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:43:29 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/11 15:43:31 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*my_map;
	t_app	my_app;
	int		ret;

	ret = 0;
	my_map = NULL;
	if (argc == 2)
	{
		my_map = read_map(argv[1]);
		ret = check_map(my_map);
		if (ret != 1)
			message_error(ret);
		init_app(&my_app, "so_long",
			ft_strlen(my_map->line), ft_lstsize(my_map));
		my_app.carte = my_map;
		mlx_key_hook(my_app.win, &player_input, &my_app);
		mlx_hook(my_app.win, 17, 0, destroy_game_data, &my_app);
		mlx_loop_hook(my_app.mlx, &routine, &my_app);
		mlx_loop(my_app.mlx);
	}
	else
		message_error(9);
	return (0);
}
