/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:46:40 by okushnir          #+#    #+#             */
/*   Updated: 2021/10/11 15:46:42 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*ft_strcpy(char *dst, const char *src)
{
	char	*orig;

	orig = dst;
	while (*src != '\0')
	{
		*dst++ = *src++;
	}
	*dst = *src;
	return (orig);
}

void	ft_strclr(char *s)
{
	while (s != NULL && *s)
		*s++ = '\0';
}

char	*check_ost(char *ost, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (ost)
	{
		p_n = ft_strchr(ost, '\n');
		if (p_n)
		{
			*p_n = '\0';
			*line = ft_strdup(ost);
			ft_strcpy(ost, ++p_n);
		}
		else
		{
			*line = ft_strdup(ost);
			ft_strclr(ost);
		}
	}
	else
		*line = ft_strnew(1);
	return (p_n);
}

void	make_line(char *ost, char **p_n, char **line, char *buf)
{
	char	*tmp;

	if (*p_n && ft_strlen(*p_n) > 1)
	{
		**p_n = '\0';
		ost = ft_strcpy(ost, ++*p_n);
	}
	else if ((*p_n && ft_strlen(*p_n) == 1))
		**p_n = '\0';
	tmp = *line;
	*line = ft_strjoin(*line, buf);
	free(tmp);
}

int	get_next_line(int fd, char **line)
{
	static char	ost[1 + 1];
	char		buf[1 + 1];
	int			byte_was_read;
	char		*p_n;

	if (read(fd, buf, 0) == -1)
		return (-1);
	byte_was_read = 1;
	p_n = check_ost(ost, line);
	while (!p_n && byte_was_read)
	{
		byte_was_read = read(fd, buf, 1);
		buf[byte_was_read] = '\0';
		p_n = ft_strchr(buf, '\n');
		make_line(ost, &p_n, line, buf);
	}
	if (byte_was_read == 0)
		return (0);
	else
		return (1);
}
