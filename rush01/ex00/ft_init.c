/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:38:45 by tnard             #+#    #+#             */
/*   Updated: 2021/07/18 18:34:56 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdlib.h>

int	ft_init_line(int **tab, int size, char *argv)
{
	int	a;
	int	b;
	int	n;

	a = 0;
	b = 1;
	n = 1;
	while (b <= size)
		tab[a][b++] = ft_getarg(argv, n++);
	b = 1;
	a = (size + 2) - 1;
	while (b <= size)
		tab[a][b++] = ft_getarg(argv, n++);
	return (1);
}

int	ft_init_column(int **tab, int size, char *argv)
{
	int	a;
	int	b;
	int	n;

	a = 1;
	b = 0;
	n = size * 2 + 1;
	while (a <= size)
		tab[a++][b] = ft_getarg(argv, n++);
	b = (size + 2) - 1;
	a = 1;
	while (a <= size)
		tab[a++][b] = ft_getarg(argv, n++);
	return (1);
}

int	ft_init_fill(int **tab, int size)
{
	int	a;
	int	b;

	a = 1;
	b = 1;
	while (a < size)
	{
		while (b <= size)
			tab[a][b++] = 0;
		b = 1;
		a++;
	}
	return (1);
}

int	**ft_init(int size, char *argv)
{
	int	**tab;
	int	a;

	a = 0;
	tab = malloc(sizeof(int *) * (size + 2));
	while (a < size + 2)
		tab[a++] = malloc(sizeof(int *) * (size + 2));
	if (ft_init_line(tab, size, argv)
		&& ft_init_column(tab, size, argv)
		&& ft_init_fill(tab, size))
		return (tab);
	return (NULL);
}
