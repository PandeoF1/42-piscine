/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 09:34:01 by tnard             #+#    #+#             */
/*   Updated: 2021/07/18 09:34:01 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_height_col(int **tab, int x, int delta, int size)
{
	int y;
	int max;
	int vmax;
	int height;

	y = (delta > 0) ? 0 : size - 1;
	max = (delta > 0) ? size : -1;
	vmax = 0;
	height = 0;
	while (y != max)
	{
		if (!tab[y][x])
			return (0);
		if (tab[y][x] > vmax)
		{
			vmax = tab[y][x];
			height++;
		}
		y += delta;
	}
	return (height);
}

int	ft_height_row(int **tab, int y, int delta, int size)
{
	int x;
	int max;
	int vmax;
	int height;

	x = (delta > 0) ? 0 : size - 1;
	max = (delta > 0) ? size : -1;
	vmax = 0;
	height = 0;
	while (x != max)
	{
		if (tab[y][x] > vmax)
		{
			vmax = tab[y][x];
			height++;
		}
		x += delta;
	}
	return (height);
}

int	ft_is_duplicate(int **tab, int x, int y, int size)
{
	int i;

	if (!tab[y][x])
		return (0);
	i = y;
	while (i--)
		if (tab[y][x] == tab[i][x])
			return (1);
	i = y;
	while (++i < size)
		if (tab[y][x] == tab[i][x])
			return (1);
	i = x;
	while (i--)
		if (tab[y][x] == tab[y][i])
			return (1);
	i = x;
	while (++i < size)
		if (tab[y][x] == tab[y][i])
			return (1);
	return (0);
}

int	ft_is_valid_value(int **tab, int x, int y, int size)
{
	if (ft_is_duplicate(tab, x, y, size)
		|| ft_height_col(tab, x, 1, size) > tab[x][size] || (y == size - 1
		&& ft_height_col(tab, x, -1, size) != tab[x][size + 1])
		|| ft_height_row(tab, y, 1, size) > tab[y][size + 2] || (x == size - 1
		&& ft_height_row(tab, y, -1, size) != tab[y][size + 3]))
		return (0);
	return (1);
}

int	ft_backtrack(int **tab, int n, int size)
{
	int i;
	int x;
	int y;

	if (n == size * size)
		return (1);
	i = 0;
	x = n % size;
	y = n / size;
	while (++i <= size)
	{
		tab[y][x] = i;
		if (ft_is_valid_value(tab, x, y, size))
		{
			if (ft_backtrack(tab, n + 1, size))
				return (1);
			tab[y][x] = 0;
		}
	}
	tab[y][x] = 0;
	return (0);
}


int	ft_check_view_line(int	**tab, int	x, int	y, int size)
{
	int	view;
	int	tmp;
	int	n;

	n = 1;
	x = 0;
	view = 1;
	tmp = tab[y][1];
	while (n <= size + 1)
		if (tab[y][1] < tab[y][n++])
			view++;
	//dprintf(1, "%d\n", view);
	if (view <= tab[y][0])
		return (1);
	return (0);
}

int	ft_solve(int **tab, int size)
{
	int i;

	i = -1;
	while (++i < size)
		if (tab[i][size] + tab[i][size + 1] > size + 1
			|| tab[i][size + 2] + tab[i][size + 3] > size + 1)
			return (0);
	return (ft_backtrack(tab, 0, size));
}