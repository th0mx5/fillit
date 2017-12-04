/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:25:38 by mmervoye          #+#    #+#             */
/*   Updated: 2017/12/04 18:29:22 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_read(t_list **lst, char *file)
{
	int			fd;
	int			ret;
	char		buf[BUFF_SIZE + 1];
	t_list		*begin;
	t_list		*tmp;

	begin = *lst;
	fd = open(file, O_RDONLY);
	if (fd < 1)
		ft_error();
	while ((ret = read(fd, buf, 1)))
	{
		tmp = ft_lstnew(buf, 1);
		ft_lstaddend(lst, tmp);
		*lst = (*lst)->next;
	}
	*lst = begin;
	*lst = (*lst)->next;
}

int				ft_count_tetrominos(t_list *lst)
{
	int			nb_t;
	char		tmp;
	char		tmp2;

	nb_t = 0;
	while (lst->next)
	{
		tmp = ((char *)lst->content)[0];
		tmp2 = ((char *)lst->next->content)[0];
		if (tmp == '\n' && tmp2 == '\n')
			nb_t++;
		lst = lst->next;
	}
	nb_t++;
	return (nb_t);
}

t_coord			**ft_settab(t_coord **tab, t_list *lst, int i, int j)
{
	t_coord		a;

	a.x = 0;
	a.y = 0;
	while ((lst->next))
	{
		if (((char*)lst->content)[0] == '\n')
		{
			if (((char *)lst->next->content)[0] == '\n')
			{
				i++;
				a.y = -1;
				j = 0;
			}
			else
				a.y++;
			a.x = -1;
		}
		if (((char*)lst->content)[0] == '#')
			tab[i][j++] = a;
		a.x++;
		lst = lst->next;
	}
	return (tab);
}

t_coord			**ft_newtab(int nb)
{
	t_coord		**tab;
	int			i;
	int			j;

	i = 0;
	j = 0;
	nb++;
	tab = (t_coord **)malloc(sizeof(tab) * (nb + 1));
	while (i < nb)
	{
		tab[i] = (t_coord *)malloc(sizeof(tab[i]) * (4));
		i++;
	}
	tab[--i] = 0;
	return (tab);
}
