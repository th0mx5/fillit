/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:52:54 by mmervoye          #+#    #+#             */
/*   Updated: 2017/12/04 19:22:45 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 32
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

int				ft_check(t_list *list);
void			ft_error(void);
int				ft_distance(t_coord c1, t_coord c2);
int				ft_check_tetros(t_coord **tab, int nb);
void			display(char **tab_final, int nb_tetros);
int				ft_sqrt(int nb);
void			ft_read(t_list **lst, char *file);
int				ft_count_tetrominos(t_list *lst);
t_coord			**ft_settab(t_coord **tab, t_list *lst, int i, int j);
t_coord			**ft_newtab(int nb);
t_coord			*ft_move_tetro(t_coord *tetro, int x, int y);
int				ft_check_tab_coord(t_coord *tab, int dir);
t_coord			**ft_smooth_tab(t_coord **tab, int nb);
int				get_next_square(int nb);
char			**ft_malloc_tab(int nb);
int				ft_check_place(char **tab, t_coord *tet, t_coord c, int size);
int				ft_solve(char **final_tab, t_coord **tetros_tab, int id_t, \
		int size);
t_list			*ft_lstnew(void const *content, size_t content_size);
int				ft_tetroisvalid(char ***tab);
int				ft_count_tetros_tab(t_coord **tetros_tab);
void			fill(char **ft_tab, t_coord **t_tab, int id_t, t_coord co);
void			defill(char **ft_tab, t_coord **t_tab, int id_t, t_coord co);
void			ft_freetab(char ***tab, t_coord **t_tab, int size);
#endif
