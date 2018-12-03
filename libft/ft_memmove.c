/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 02:44:29 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/05/31 23:46:30 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dest;
	unsigned char *sorc;

	dest = (unsigned char*)dst;
	sorc = (unsigned char*)src;
	if (len == 0)
		return (dest);
	if (sorc < dest)
	{
		while (len)
		{
			dest[len - 1] = sorc[len - 1];
			len--;
		}
		return (dest);
	}
	else
	{
		ft_memcpy(dest, src, len);
		return (dest);
	}
}
