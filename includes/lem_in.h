/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:52:12 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/10/15 14:06:42 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct	s_rm
{
	char	*name;
	int		x;
	int		y;
	int		size;
}				t_rm;

typedef struct	s_lem_in
{
	char	**data;
	int		ants;
	t_rm	*rm;
	char	**links;
	int		**map;
	int		rooms;
	int		link;
	int		start;
	int		end;
	char	*lst;
	int		len;
	int		*rmf;
}				t_lem_in;

t_lem_in		*initializer_1(void);
void			initializer_2(t_lem_in *lem);
void			converter(t_lem_in *lem);
void			ft_free(t_lem_in *lem);

int				data_reading(t_lem_in *lem);
int				store_controller(t_lem_in *lem);
void			room_storing(t_lem_in *lem, char *str);
void			store_ants(t_lem_in *lem, char *str);
void			rooms_order_1(t_lem_in *lem);
void			rooms_order_2(t_lem_in *lem, t_rm *temp);

int				check_in_list(char *node, char *list);
void			check_matching(t_lem_in *lem, char **str, int i, int j);
char			*new_room(t_lem_in *lem, char *lst, int rm);
int				find_length(char *lst);

void			column_row(t_lem_in *lem);
int				row_minus (t_lem_in *lem, char *lst, int y, int x);
int				row_plus (t_lem_in *lem, char *lst, int y, int x);
int				column_minus (t_lem_in *lem, char *lst, int y, int x);
int				column_plus (t_lem_in *lem, char *lst, int y, int x);

void			rooms_sorting(t_lem_in *lem);
void			printer(t_lem_in *lem);
void			ants_printing(t_lem_in *lem, int ant, int rm);
void			ants_moving(t_lem_in *lem);
int				moving_1(t_lem_in *lem, int ant, int rm, int count);

int				errors_check_up(t_lem_in *lem);
#endif
