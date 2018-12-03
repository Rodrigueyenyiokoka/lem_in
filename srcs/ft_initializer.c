/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:55:52 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/21 12:55:55 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_lem_in	*initializer_1(void)
{
	t_lem_in	*lem;
	int			i;

	lem = (t_lem_in *)malloc(sizeof(t_lem_in));
	lem->data = (char **)malloc(sizeof(char *) * 3000);
	lem->ants = 0;
	lem->rm = (t_rm *)malloc(sizeof(t_rm) * 1000);
	i = 0;
	while (i < 1000)
	{
		lem->rm[i].name = NULL;
		lem->rm[i].x = 0;
		lem->rm[i].y = 0;
		lem->rm[i++].size = 0;
	}
	lem->links = (char **)malloc(sizeof(char *) * 2000);
	i = 0;
	initializer_2(lem);
	return (lem);
}

void		initializer_2(t_lem_in *lem)
{
	int			i;

	lem->map = NULL;
	lem->rooms = 0;
	lem->link = 0;
	lem->start = 0;
	lem->end = 0;
	lem->len = 999;
	lem->rmf = (int *)malloc(sizeof(int) * 1000);
	i = 0;
	while (i < 1000)
		lem->rmf[i++] = -1;
	lem->lst = (char *)malloc(sizeof(char) * 1000);
	lem->lst = NULL;
}

void		converter(t_lem_in *lem)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	lem->map = (int **)malloc(sizeof(int *) * lem->rooms);
	while (i < lem->rooms)
		lem->map[i++] = (int *)malloc(sizeof(int) * lem->rooms);
	while (k < lem->link)
	{
		str = ft_strsplit(lem->links[k++], '-');
		i = -1;
		while (++i < lem->rooms)
		{
			j = -1;
			while (++j < lem->rooms)
				check_matching(lem, str, i, j);
		}
		j = 0;
		while (*(str + j))
			free(str[j++]);
		free(str);
	}
}

void		ft_free(t_lem_in *lem)
{
	int i;

	i = 0;
	free(lem->data);
	free(lem->rm);
	while (lem->links[i])
	{
		free(lem->links[i]);
		lem->links[i] = NULL;
		i++;
	}
	free(lem->links);
	i = 0;
	while (i < lem->rooms)
	{
		free(lem->map[i]);
		lem->map[i] = NULL;
		i++;
	}
	free(lem->map);
	free(lem->lst);
	free(lem->rmf);
}
