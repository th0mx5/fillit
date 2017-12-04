/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:44:22 by mmervoye          #+#    #+#             */
/*   Updated: 2017/12/04 19:48:26 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				get_next_square(int nb)
{
	int			i;

	i = 0;
	while (nb > (i * i))
		i++;
	return (i);
}

char			**ft_malloc_tab(int nb)
{
	char		**tab;
	int			i;

	i = 0;
	tab = (char **)malloc(sizeof(tab) * nb + 1);
	while (i < nb)
	{
		tab[i] = (char *)malloc(sizeof(tab[i]) * nb + 1);
		ft_memset(tab[i], '.', nb);
		tab[i][nb] = 0;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

int				ft_check_place(char **tab_final, t_coord *tetro, t_coord co,\
		int size)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (!(co.x + tetro[i].x >= 0 && co.y + tetro[i].y >= 0))
			return (1);
		if (!(co.x + tetro[i].x < size && co.y + tetro[i].y < size))
			return (2);
		if (tab_final[co.y + tetro[i].y][co.x + tetro[i].x] != '.')
			return (3);
		i++;
	}
	return (0);
}

int				ft_count_tetros_tab(t_coord **tetros_tab)
{
	int i;

	i = 0;
	while (tetros_tab[i])
		i++;
	return (i);
}

int				ft_solve(char **final_tab, t_coord **tetros_tab, int id_t,\
		int size)
{
	t_coord		co;

	co.x = 0;
	co.y = 0;
	if (id_t == ft_count_tetros_tab(tetros_tab))
		display(final_tab, size);
	while (final_tab[co.y])
	{
		while (final_tab[co.y][co.x])
		{
			if (!ft_check_place(final_tab, tetros_tab[id_t], co, size))
			{
				fill(final_tab, tetros_tab, id_t, co);
				if (ft_solve(final_tab, tetros_tab, id_t + 1, size))
					defill(final_tab, tetros_tab, id_t, co);
			}
			co.x++;
		}
		co.x = 0;
		co.y++;
	}
	if (id_t == 0 && co.y == size)
		ft_freetab(&final_tab, tetros_tab, size);
	return (1);
}
