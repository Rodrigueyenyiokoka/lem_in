/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:56:20 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/21 12:56:45 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	moving_2(t_lem_in *lem, int ant, int rm, int count)
{
	lem->rm[lem->rmf[rm - 1]].size--;
	lem->rm[lem->rmf[rm]].size++;
	if (rm == lem->len - 1)
	{
		ants_printing(lem, ant + (count - ant), rm);
		moving_1(lem, ant + (count - ant) + 1, rm - 1, count + 1);
	}
	else
	{
		ants_printing(lem, ant, rm);
		moving_1(lem, ant + 1, rm - 1, count);
	}
}

int		moving_1(t_lem_in *lem, int ant, int rm, int count)
{
	if (lem->rm[lem->rmf[lem->len - 1]].size == lem->ants)
		return (1);
	if (rm <= 0)
	{
		write(1, "\n", 1);
		moving_1(lem, 1, lem->len - 1, count);
		return (0);
	}
	else if (lem->rm[lem->rmf[rm - 1]].size == 0
		&& lem->rm[lem->rmf[rm]].size >= 1)
		return (0);
	else if (lem->rm[lem->rmf[rm - 1]].size >= 1)
	{
		moving_2(lem, ant, rm, count);
	}
	moving_1(lem, ant, rm - 1, count);
	return (0);
}

void	ants_moving(t_lem_in *lem)
{
	lem->rm[lem->rmf[0]].size = lem->ants;
	moving_1(lem, 1, lem->len - 1, 1);
	write(1, "\n", 1);
}

void	rooms_sorting(t_lem_in *lem)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	s = ft_strsplit(lem->lst, '-');
	while (*(s + i))
	{
		j = 0;
		while (j <= lem->rooms - 1)
		{
			if (ft_strequ(*(s + i), lem->rm[j].name))
				lem->rmf[i] = j;
			j++;
		}
		free(s[i]);
		i++;
	}
	free(s);
}
