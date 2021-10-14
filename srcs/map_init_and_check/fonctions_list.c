/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:43:06 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/11 15:43:08 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_map	*ft_lstnew(char *line)
{
	t_map	*my_elem;

	my_elem = (void *)0;
	my_elem = (t_map *)malloc(sizeof(t_map));
	if (my_elem != (void *)0)
	{
		my_elem->line = line;
		my_elem->next = (void *)0;
	}
	return (my_elem);
}

t_map	*ft_lstlast(t_map *lst)
{
	t_map	*p;
	t_map	*res;

	p = lst;
	res = NULL;
	while (p)
	{
		if (p->next == NULL)
			res = p;
		p = p->next;
	}
	return (res);
}

void	ft_lstadd_back(t_map **alst, t_map *new)
{
	t_map	*last;

	last = ft_lstlast(*alst);
	if (alst == (void *)0 || new == (void *)0)
		return ;
	if (*alst == (void *)0)
	{
		*alst = new;
		return ;
	}
	if (new != (void *)0)
		last->next = new;
}

int	ft_lstsize(t_map *lst)
{
	int		i;
	t_map	*p;

	i = 0;
	p = lst;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}
