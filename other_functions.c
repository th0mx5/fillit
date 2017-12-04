/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:46:34 by mmervoye          #+#    #+#             */
/*   Updated: 2017/12/04 19:12:29 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coord				*ft_move_tetro(t_coord *tetro, int x, int y)
{
	int			j;

	j = 0;
	while (j < 4)
	{
		tetro[j].x = tetro[j].x + x;
		tetro[j].y = tetro[j].y + y;
		j++;
	}
	return (tetro);
}

int					ft_check_tab_coord(t_coord *tab, int dir)
{
	int			j;

	j = 0;
	while (j < 4)
	{
		if (tab[j].x == 0 && dir == 1)
			return (1);
		if (tab[j].y == 0 && dir == 2)
			return (1);
		j++;
	}
	return (0);
}

t_coord				**ft_smooth_tab(t_coord **tab, int nb)
{
	int			i;

	i = 0;
	while (i < nb)
	{
		if (!ft_check_tab_coord(tab[i], 1))
			tab[i] = ft_move_tetro(tab[i], -1, 0);
		else if (!ft_check_tab_coord(tab[i], 2))
			tab[i] = ft_move_tetro(tab[i], 0, -1);
		else
			i++;
	}
	return (tab);
}

void				fill(char **f_tab, t_coord **t_tab, int id_t, t_coord co)
{
	f_tab[co.y + t_tab[id_t][0].y][co.x + t_tab[id_t][0].x] = (65 + id_t);
	f_tab[co.y + t_tab[id_t][1].y][co.x + t_tab[id_t][1].x] = (65 + id_t);
	f_tab[co.y + t_tab[id_t][2].y][co.x + t_tab[id_t][2].x] = (65 + id_t);
	f_tab[co.y + t_tab[id_t][3].y][co.x + t_tab[id_t][3].x] = (65 + id_t);
}

void				defill(char **f_tab, t_coord **t_tab, int id_t, t_coord co)
{
	f_tab[co.y + t_tab[id_t][0].y][co.x + t_tab[id_t][0].x] = '.';
	f_tab[co.y + t_tab[id_t][1].y][co.x + t_tab[id_t][1].x] = '.';
	f_tab[co.y + t_tab[id_t][2].y][co.x + t_tab[id_t][2].x] = '.';
	f_tab[co.y + t_tab[id_t][3].y][co.x + t_tab[id_t][3].x] = '.';
}
