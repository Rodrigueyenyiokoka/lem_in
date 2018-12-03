/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_store_order.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:58:00 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/21 12:58:09 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		data_reading(t_lem_in *lem)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strequ(line, ""))
		{
			free(line);
			return (0);
		}
		else
			lem->data[i++] = ft_strdup(line);
		free(line);
	}
	if (i == 0)
	{
		ft_putstr("Error : Empty file\n");
		exit(0);
	}
	lem->data[i] = NULL;
	return (1);
}

int		store_controller(t_lem_in *lem)
{
	int		i;
	char	*p;

	i = 0;
	while (lem->data[i])
	{
		if (ft_strequ(lem->data[i], "##start"))
			lem->start = lem->rooms;
		else if (ft_strequ(lem->data[i], "##end"))
			lem->end = lem->rooms;
		else if ((p = ft_strchr(lem->data[i], ' ')) &&
				lem->data[i][0] != '#' && (p = ft_strchr(p + 1, ' ')))
			room_storing(lem, lem->data[i]);
		else if ((p = ft_strchr(lem->data[i], '-')) && ft_strcmp(p + 1, ""))
			lem->links[lem->link++] = ft_strdup(lem->data[i]);
		else if (lem->data[i][0] != '#' && !ft_strchr(lem->data[i], ' '))
			lem->ants = ft_atoi(lem->data[i]);
		i++;
	}
	lem->links[lem->link] = NULL;
	lem->rm[lem->rooms].name = NULL;
	rooms_order_1(lem);
	return (1);
}

void	room_storing(t_lem_in *lem, char *str)
{
	char	**s;
	int		i;

	i = 0;
	s = ft_strsplit(str, ' ');
	lem->rm[lem->rooms].name = ft_strdup(s[0]);
	lem->rm[lem->rooms].x = ft_atoi(s[1]);
	lem->rm[lem->rooms++].y = ft_atoi(s[2]);
	while (*(s + i))
		free(s[i++]);
	free(s);
}

void	rooms_order_1(t_lem_in *lem)
{
	t_rm	temp;

	if (lem->start != 0)
	{
		rooms_order_2(lem, &temp);
	}
	if (lem->end != lem->rooms - 1)
	{
		temp.name = lem->rm[lem->rooms - 1].name;
		temp.x = lem->rm[lem->rooms - 1].x;
		temp.y = lem->rm[lem->rooms - 1].y;
		lem->rm[lem->rooms - 1].name = lem->rm[lem->end].name;
		lem->rm[lem->rooms - 1].x = lem->rm[lem->end].x;
		lem->rm[lem->rooms - 1].y = lem->rm[lem->end].y;
		lem->rm[lem->end].name = temp.name;
		lem->rm[lem->end].x = temp.x;
		lem->rm[lem->end].y = temp.y;
	}
}

void	rooms_order_2(t_lem_in *lem, t_rm *temp)
{
	temp->name = lem->rm[0].name;
	temp->x = lem->rm[0].x;
	temp->y = lem->rm[0].y;
	lem->rm[0].name = lem->rm[lem->start].name;
	lem->rm[0].x = lem->rm[lem->start].x;
	lem->rm[0].y = lem->rm[lem->start].y;
	lem->rm[lem->start].name = temp->name;
	lem->rm[lem->start].x = temp->x;
	lem->rm[lem->start].y = temp->y;
}
