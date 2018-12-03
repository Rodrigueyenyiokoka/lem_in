/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:55:31 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/21 12:55:36 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_in_list(char *node, char *list)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	s = ft_strsplit(list, '-');
	while (*(s + i))
	{
		if (ft_strequ(node, s[i]))
		{
			j = 0;
			while (*(s + i + j))
				free(s[i + j++]);
			free(s);
			return (1);
		}
		free(s[i++]);
	}
	free(s);
	return (0);
}

char	*new_room(t_lem_in *lem, char *lst, int rm)
{
	char *s;

	if (!check_in_list(lem->rm[rm].name, lst))
	{
		s = ft_strjoin(lst, "-");
		lst = ft_strjoin(s, lem->rm[rm].name);
		free(s);
		if (rm == lem->rooms - 1)
		{
			if (find_length(lst) < lem->len)
			{
				lem->len = find_length(lst);
				free(lem->lst);
				lem->lst = ft_strdup(lst);
			}
		}
	}
	return (lst);
}

int		find_length(char *lst)
{
	char	**str;
	int		len;

	str = ft_strsplit(lst, '-');
	len = 0;
	while (*(str + len))
		free(str[len++]);
	free(str);
	return (len);
}

void	ants_printing(t_lem_in *lem, int ant, int rm)
{
	write(1, "L", 1);
	ft_putnbr(ant);
	write(1, "-", 1);
	ft_putstr(lem->rm[lem->rmf[rm]].name);
	if (ft_strcmp(lem->rm[lem->rmf[rm]].name, lem->rm[lem->end].name)
		&& (ant != lem->ants))
		write(1, " ", 1);
	if (ft_strequ(lem->rm[lem->rmf[rm]].name, lem->rm[lem->end].name)
		&& (ant != lem->ants))
		write(1, " ", 1);
}

void	printer(t_lem_in *lem)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	while (lem->data[i])
	{
		s = ft_strjoin(lem->data[i++], "\n");
		ft_putstr(s);
		j = 0;
		free(s);
	}
}
