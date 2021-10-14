/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_fonctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:46:14 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/11 15:46:16 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr( int n)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = (unsigned int)(-1 * n);
		ft_putchar('-');
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

void	*bit_copy(void *dst, const void *src, int j)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	if (!dst && !src)
		return ((void *)0);
	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	*(p_dst + j) = *(p_src + j);
	return (dst);
}

int	is_texture_exist(const char *filename)
{
	int	fd;

	fd = 0;
	fd = open(filename, O_RDONLY);
	if (fd > 0)
		close(fd);
	else
		message_error(10);
	return (1);
}
