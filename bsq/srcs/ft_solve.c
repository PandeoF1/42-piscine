/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 02:20:27 by molatrec          #+#    #+#             */
/*   Updated: 2021/07/27 16:09:39 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

int	**ft_obstacle_map(char **map)
{
	int	x_max;
	int	y_max;
	int	**map_obstacles;
	int	i;//test
	int	j;//test

	x_max = ft_map_length(map);
	y_max = ft_map_depth(map);
	map_obstacles = ft_create_map_obstacle(x_max, y_max);
	if (!map_obstacles)
		return (0);
	ft_fill_map_obstacles(map_obstacles, map);
	i = -1;//test
	while (++i < x_max)
	{
		j = -1;
		while (++j < y_max)
		{
			printf("%d", map_obstacles[i][j]);
		}
		printf("\n");
	}//fin test
	return (map_obstacles);
}

t_bsq	ft_best_possible_fill(t_bsq best_possible, int i, int j, int size)
{
	best_possible.x = i;
	best_possible.y = j;
	best_possible.size = size;
	return (best_possible);
}

int	ft_square_fits(int **obstacles_map, int i, int j, int size)
{
	if (i - 1 < 0 && j - 1 < 0)
	{
		if (obstacles_map[size][size] == 0)
			return (1);
	}
	else if (i - 1 < 0)
	{
		if (obstacles_map[size][size] - obstacles_map[i][j - 1] == 0)
			return (1);
	}
	else if (j - 1 < 0)
	{
		if (obstacles_map[size][size] - obstacles_map[i - 1][j] == 0)
			return (1);
	}
	else
		if (obstacles_map[size][size] - obstacles_map[i - 1][j]
				- obstacles_map[i][j - 1]
				+ obstacles_map[i - 1][j - 1] == 0)
			return (1);
	return (0);
}

void	ft_show(char **map, t_bsq best_possible)
{
	int	a;
	int	b;

	a = -1;
	b = -1;

	while (++a < best_possible.size)
	{
		b = -1;
		while (++b < best_possible.size)
		{
			map[best_possible.x + a][best_possible.y + b] = 'x';
		}
	}
	a = 0;
	while (map[a])
		dprintf(1, "%s\n", map[a++]);
}

t_bsq	ft_solve(char **map, int i, int j)
{
	int		**obstacles_map;
	int		size;
	t_bsq	best_possible;

	best_possible.size = 0;
	obstacles_map = ft_obstacle_map(map);
	if (!obstacles_map)
		return (best_possible);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			size = best_possible.size;
			while (ft_square_fits(obstacles_map, i, j, size - (size != 0)))
			{
				printf("%d %d\n", i, j);
				size++;
			}
			if (--size > best_possible.size)
			{
				printf("!\n");
				best_possible
					= ft_best_possible_fill(best_possible, i, j, size);
			}
		}
	}
	ft_free(obstacles_map, map);
	return (best_possible);
}

void	ft_printing(char **map)
{
	t_bsq	answer;
	int		i;
	int		j;

	i = -1;
	answer = ft_solve(map, -1, 0);
	while (++i < answer.size)
	{
		j = -1;
		while (++j < answer.size)
		{
			map[answer.x + i][answer.y + j] = 'x';
		}
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			ft_putchar(map[i][j]);
		}
		ft_putchar('\n');
	}
}
