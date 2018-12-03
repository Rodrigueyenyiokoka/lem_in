/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 01:20:03 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/06/05 18:06:47 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = (size_t)ft_strlen((char *)dst);
	s_len = (size_t)ft_strlen((char *)src);
	i = d_len;
	while ((*src) && ((d_len + 1) < size))
	{
		dst[d_len++] = *src++;
	}
	dst[d_len] = '\0';
	if (i > size)
		return (s_len + size);
	else
		return (s_len + i);
}
