/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 02:58:48 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/06/06 04:45:25 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*element;
	t_list	*noob;

	if (!lst || !f)
		return (NULL);
	element = f(lst);
	noob = element;
	while (lst->next)
	{
		lst = lst->next;
		if (!(element->next = f(lst)))
		{
			free(element->next);
			return (NULL);
		}
		else
			element = element->next;
	}
	return (noob);
}
