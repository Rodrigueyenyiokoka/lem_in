/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 00:45:02 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/08/08 15:28:36 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int					get_next_line(int const fd, char **line)
{
	int				bytes_size;
	char			buff[BUFF_SIZE + 1];
	static char		*stock_buff = NULL;

	if (stock_buff && read_line(&stock_buff, line))
		return (1);
	while ((bytes_size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes_size] = '\0';
		stock_buff = str_join(stock_buff, buff);
		if (read_line(&stock_buff, line))
			return (1);
	}
	if (bytes_size < 0)
		return (-1);
	if (stock_buff && *stock_buff)
	{
		*line = ft_strdup(stock_buff);
		ft_strdel(&stock_buff);
		return (1);
	}
	if (bytes_size)
		return (1);
	return (0);
}

char				*str_join(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*join;

	l1 = (s1) ? ft_strlen(s1) : 0;
	l2 = ft_strlen(s2);
	join = ft_strnew(l1 + l2);
	if (join)
	{
		if (s1)
			ft_memcpy(join, s1, l1);
		ft_memcpy(join + l1, s2, l2);
	}
	if (s1)
		ft_strdel(&s1);
	return (join);
}

int					read_line(char **stock_buff, char **line)
{
	char	*tmp;

	if ((tmp = ft_strchr(*stock_buff, '\n')))
	{
		*line = ft_strsub(*stock_buff, 0, tmp - *stock_buff);
		ft_strcpy(*stock_buff, tmp + 1);
		return (1);
	}
	return (0);
}
