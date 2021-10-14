/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:46:54 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/11 15:46:56 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew(int count)
{
	char	*arr;
	int		i;

	i = 0;
	arr = (char *)malloc(sizeof(char) * count);
	if (arr != (void *)0)
	{
		while (i < count)
		{
			arr[i] = '\0';
			i++;
		}
	}
	return (arr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*r;

	if (c > 255)
		c = c - 256;
	r = s;
	while (*r)
	{
		if (*r == c)
			return ((char *)r);
		r++;
	}
	if (c == '\0' && !(*r))
		return ((char *)r);
	return ((void *)0);
}

char	*ft_strdup(const char *s1)
{
	char		*mon_str;
	size_t		i;

	i = 0;
	mon_str = (void *)0;
	mon_str = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (mon_str != (void *)0)
	{
		while (i < ft_strlen(s1))
		{
			mon_str[i] = s1[i];
			i++;
		}
		mon_str[i] = '\0';
	}
	return (mon_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return ((char *)malloc(0));
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == (void *)0)
		return ((void *)0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
