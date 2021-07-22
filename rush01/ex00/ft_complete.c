/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 09:34:01 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:28:50 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_check_view_colum_total(int	**tab, int	x, int	y, int size)
{
	int	view;
	int	tmp;
	int	n;

	n = 1;
	view = 1;
	tmp = tab[1][x];
	if (y != size)
		return (1);
	while (n <= size)
	{
		if (tmp < tab[n++][x])
		{
			tmp = tab[n - 1][x];
			view++;
		}
	}
	if (view == tab[0][x])
		return (1);
	return (0);
}

int	ft_check_view_line_total(int	**tab, int	x, int	y, int size)
{
	int	view;
	int	tmp;
	int	n;

	n = 1;
	view = 1;
	tmp = tab[y][1];
	if (x != size)
		return (1);
	while (n <= size)
	{
		if (tmp < tab[y][n++])
		{
			tmp = tab[y][n - 1];
			view++;
		}
	}
	if (view == tab[y][0])
		return (1);
	return (0);
}

int	ft_check_total(int **tab, int x, int y, int size)
{
	if (ft_check_view_line_total(tab, x, y, size)
		&& ft_check_view_colum_total(tab, x, y, size)
		&& ft_check(tab, size, x, y))
		return (1);
	return (0);
}

int	ft_solve(int **tab, int x, int y, int size)
{
	int	n;

	n = 0;
	while (++n <= size)
	{
		tab[y][x] = n;
		if (ft_check_total(tab, x, y, size))
		{
			if (x == size && y == size)
				return (1);
			else if (x < size)
			{
				if (ft_solve(tab, x + 1, y, size))
					return (1);
			}
			else if (y < size)
			{
				if (ft_solve(tab, 1, y + 1, size))
					return (1);
			}
			tab[y][x] = 0;
		}
	}
	tab[y][x] = 0;
	return (0);
}
