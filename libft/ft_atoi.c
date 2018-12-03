/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 00:57:44 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/08/14 15:41:11 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	nbr;
	int			negative;

	nbr = 0;
	negative = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\n'
			|| *str == '\r' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
		negative = (*str++ == '-') ? -1 : 1;
	while (*str && ft_isdigit(*str))
	{
		if (nbr == 2147483648 && negative == -1)
			return (-2147483648);
		if (nbr > 2147483647)
		{
			if (negative == 1)
				return (-1);
			return (0);
		}
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr * negative);
}
