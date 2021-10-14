/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map_list_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:45:32 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/11 15:45:36 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	ft_lstdelone(t_map *lst)
{
	if (lst == (void *)0)
		return ;
	free(lst->line);
	free(lst);
}

void	ft_lstclear(t_map **lst)
{
	t_map	*tmp_c;
	t_map	*tmp_n;

	tmp_c = *lst;
	while (tmp_c != (void *)0)
	{
		tmp_n = tmp_c->next;
		ft_lstdelone(tmp_c);
		tmp_c = tmp_n;
	}
	*lst = (void *)0;
}
