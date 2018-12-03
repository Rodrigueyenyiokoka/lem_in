/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 01:59:00 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/05/31 22:15:46 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char *x;
	char *y;

	if (n == 0 || dst == src)
		return (dst);
	x = (char *)dst;
	y = (char *)src;
	while (--n)
		*x++ = *y++;
	*x = *y;
	return (dst);
}
