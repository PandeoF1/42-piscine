/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:49:18 by tnard             #+#    #+#             */
/*   Updated: 2021/07/15 15:49:10 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		n;
	int		l;

	l = 0;
	n = 0;
	while (src[l])
		l++;
	ptr = malloc(sizeof(src) * l + 1);
	if (ptr == NULL)
		return (NULL);
	while (src[n])
	{
		ptr[n] = src[n];
		n++;
	}
	ptr[n] = '\0';
	return (ptr);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	i = 0;
	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	while (i < ac)
	{
		tab[i].copy = malloc(sizeof(char *) * ft_strlen(av[i]) + 1);
		tab[i].str = malloc(sizeof(char *) * ft_strlen(av[i]) + 1);
		if (tab[i].str == NULL || tab[i].copy == NULL)
			return (NULL);
		tab[i].size = ft_strlen(av[i]);
		tab[i].copy = ft_strdup(av[i]);
		tab[i].str = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}
