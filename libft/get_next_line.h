/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 16:10:08 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/08/08 15:22:11 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8

int		get_next_line(int const fd, char **line);
int		read_line(char **stock_buff, char **line);
char	*str_join(char *str1, char *str2);

#endif
