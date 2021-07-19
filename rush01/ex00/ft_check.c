/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 09:13:48 by tnard             #+#    #+#             */
/*   Updated: 2021/07/18 09:13:51 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>
#include <unistd.h>

int	ft_check_line(int	**tab, int size, int x, int y)
{
	int	tmp;
	int	n;

	tmp = tab[y][x];
	n = 0;
	x = 1;
	while (x <= size)
	{
		if (tmp == tab[y][x])
			n++;
		x++;
	}
	x = 1;
	y++;
	if (n <= 1)
	{
		return (1);
	}
	return (0);
}

int	ft_check_column(int **tab, int size, int x, int y)
{
	int	tmp;
	int	n;

	n = 0;
	tmp = tab[y][x];
	y = 1;
	while (y <= size)
	{
		if (tmp == tab[y][x])
			n++;
		y++;
	}
	if (n <= 1)
	{
		return (1);
	}
	return (0);
}

int	ft_check(int **tab, int size, int x, int y)
{
	if (ft_check_line(tab, size, x, y) == 1
		&& ft_check_column(tab, size, x, y) == 1)
	{
		return (1);
	}
	return (0);
}
