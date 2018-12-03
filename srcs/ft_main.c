/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:57:04 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/21 12:57:13 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	t_lem_in	*lem;

	lem = initializer_1();
	data_reading(lem);
	store_controller(lem);
	if (errors_check_up(lem))
		exit(0);
	converter(lem);
	column_row(lem);
	if (!lem->lst)
	{
		ft_putstr("Error : No valid solution\n");
		exit(0);
	}
	rooms_sorting(lem);
	printer(lem);
	write(1, "\n", 1);
	ants_moving(lem);
	ft_free(lem);
	free(lem);
	return (0);
}
