/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:23:31 by mmervoye          #+#    #+#             */
/*   Updated: 2017/11/14 09:33:11 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strpbrk(char *str1, const char *str2)
{
	size_t		i;

	i = 0;
	while (*str1)
	{
		while (str2[i])
		{
			if (str2[i] == *str1)
				return (str1);
			i++;
		}
		i = 0;
		str1++;
	}
	return (NULL);
}
