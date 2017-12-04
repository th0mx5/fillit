/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:52:38 by mmervoye          #+#    #+#             */
/*   Updated: 2017/12/04 19:24:01 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			display(char **tab_final, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		ft_putendl(tab_final[i]);
		i++;
	}
	exit(EXIT_SUCCESS);
}

void			ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

void			ft_freetab(char ***tab, t_coord **t_tab, int size)
{
	free(*tab);
	*tab = ft_malloc_tab(size + 1);
	ft_solve(*tab, t_tab, 0, size + 1);
}

int				main(int argc, char **argv)
{
	int			nb_tetros;
	char		**tab_final;
	int			size;
	t_coord		**tab;
	t_list		*lst;

	if (argc != 2)
	{
		ft_putendl_fd("usage: ./fillit [valid file]", 1);
		exit(EXIT_FAILURE);
	}
	lst = ft_lstnew(NULL, 1);
	ft_read(&lst, argv[1]);
	if (ft_check(lst))
		ft_error();
	nb_tetros = ft_count_tetrominos(lst);
	size = get_next_square(nb_tetros * 4);
	tab = ft_newtab(nb_tetros);
	tab = ft_settab(tab, lst, 0, 0);
	if (ft_check_tetros(tab, nb_tetros) != 42)
		ft_error();
	tab = ft_smooth_tab(tab, nb_tetros);
	tab_final = ft_malloc_tab(size);
	ft_solve(tab_final, tab, 0, size);
	return (0);
}
