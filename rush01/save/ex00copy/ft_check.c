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

int	ft_check_line(int	**grid, int size)
{
	int	i;
	int	j;
	int	tab[150][150];

	i = 1;
	j = 1;
	while (i < size + 1)
	{
		while (j < size + 1)
		{
			if (tab[i][grid[i][j]]++ == 1 && grid[i][j] != 0)
			{
				printf("Erreur a ligne");
				return (0);
			}
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

int	ft_check_column(int	**grid, int size)
{
	int	i;
	int	j;
	int	tab[100][100];

	i = 1;
	j = 1;
	while (i < size + 1)
	{
		while (j < size + 1)
		{
			if (tab[grid[j][i]][i]++ == 1 && grid[j][i] != 0)
			{
				printf("Erreur a colonne");
				return (0);
			}
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

int	ft_check(int	**grid, int	size)
{
	if (ft_check_line(grid, size) == 1 && ft_check_column(grid, size) == 1)
	{
		return (1);
	}
	return (0);
}
