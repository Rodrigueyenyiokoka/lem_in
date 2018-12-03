/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:57:31 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/21 12:57:38 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		column_plus(t_lem_in *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[y][lem->rooms - 1] == 1)
	{
		lst = new_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		column_plus(lem, lst, y, x + 1);
		lst = new_room(lem, lst, x);
		row_plus(lem, lst, y - 1, x);
		row_minus(lem, lst, y + 1, x);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		column_plus(lem, lst, y, x + 1);
	return (0);
}

int		column_minus(t_lem_in *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[y][lem->rooms - 1] == 1)
	{
		lst = new_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		column_minus(lem, lst, y, x - 1);
		lst = new_room(lem, lst, x);
		row_plus(lem, lst, y - 1, x);
		row_minus(lem, lst, y + 1, x);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		column_minus(lem, lst, y, x - 1);
	return (0);
}

int		row_plus(t_lem_in *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[lem->rooms - 1][x] == 1)
	{
		lst = new_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		row_plus(lem, lst, y - 1, x);
		lst = new_room(lem, lst, y);
		column_minus(lem, lst, y, x - 1);
		column_plus(lem, lst, y, x + 1);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		row_plus(lem, lst, y - 1, x);
	return (0);
}

int		row_minus(t_lem_in *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[lem->rooms - 1][x] == 1)
	{
		lst = new_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		row_minus(lem, lst, y + 1, x);
		lst = new_room(lem, lst, y);
		column_minus(lem, lst, y, x - 1);
		column_plus(lem, lst, y, x + 1);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		row_minus(lem, lst, y + 1, x);
	return (0);
}

void	column_row(t_lem_in *lem)
{
	char *tmp;

	tmp = ft_strdup(lem->rm[0].name);
	column_plus(lem, tmp, 0, 0);
	free(tmp);
}
