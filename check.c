/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:49:53 by mmervoye          #+#    #+#             */
/*   Updated: 2017/12/04 18:37:02 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_check_elem(char tmp, char tmp2)
{
	static int	count_h;
	static int	count_p;

	if (!(tmp == '.' || tmp == '#' || tmp == '\n'))
		ft_error();
	if (tmp == '#')
		count_h++;
	if (tmp == '.')
		count_p++;
	if (tmp == '\n' && tmp2 == '\n')
	{
		if (count_h != 4 || count_p != 12)
			ft_error();
		else
		{
			count_h = 0;
			count_p = 0;
		}
	}
}

int				ft_check(t_list *list)
{
	int			count_elem_line;
	char		tmp;
	char		tmp2;

	count_elem_line = 0;
	if (!list)
		return (-1);
	while (list)
	{
		tmp = ((char *)list->content)[0];
		if (list->next)
			tmp2 = ((char *)list->next->content)[0];
		count_elem_line++;
		ft_check_elem(tmp, tmp2);
		if (tmp == '\n')
		{
			if (count_elem_line != 5)
				return (2);
			count_elem_line = ((tmp2 == '\n') ? 4 : 0);
		}
		list = list->next;
	}
	return (0);
}

int				ft_distance(t_coord c1, t_coord c2)
{
	return (ft_sqrt((c2.x - c1.x) * (c2.x - c1.x)) + ((c2.y - c1.y) * \
				(c2.y - c1.y)));
}

int				ft_check_tetros(t_coord **tab, int nb)
{
	int			nb_links;
	int			i;
	int			j;
	int			k;

	i = -1;
	while (++i < nb)
	{
		j = 0;
		nb_links = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				if (k != j && ft_distance(tab[i][j], tab[i][k]) == 1)
					nb_links++;
				k++;
			}
			j++;
		}
		if (nb_links < 5)
			return (-1);
	}
	return (42);
}
