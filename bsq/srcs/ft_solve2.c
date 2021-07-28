/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 06:40:33 by molatrec          #+#    #+#             */
/*   Updated: 2021/07/28 12:24:39 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

int	ft_map_length(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

int	ft_map_depth(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		i++;
	}
	return (i);
}

void	ft_fill_map_obstacles(int **fill, char **map, char *value)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i] != 0)
	{
		j = -1;
		while (map[i][++j] != 0)
		{
			if (i == 0 && j == 0)
				fill[i][j] = (map[i][j] == value[1]);
			else if (i == 0 && j > 0)
				fill[i][j] = fill[i][j - 1] + (map[i][j] == value[1]);
			else if (j == 0 && i > 0)
				fill[i][j] = fill[i - 1][j] + (map[i][j] == value[1]);
			else
				fill[i][j] = fill[i - 1][j] + fill[i][j - 1]
					- fill[i - 1][j - 1] + (map[i][j] == value[1]);
		}
	}
}

void	ft_free(int **to_free, char **map)
{
	int	i;

	i = -1;
	while (++i < ft_map_length(map))
		free(to_free[i]);
	free(to_free);
}

int	**ft_create_map_obstacle(int x, int y)
{
	int	i;
	int	**map;

	i = -1;
	map = (int **)malloc(sizeof(int *) * x);
	if (!map)
		return (0);
	while (++i < y)
	{
		map[i] = (int *)malloc(sizeof(int) * y);
	}
	return (map);
}
