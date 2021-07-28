/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 02:20:27 by molatrec          #+#    #+#             */
/*   Updated: 2021/07/28 12:24:35 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

t_bsq	ft_best_possible_fill(t_bsq best_possible, int i, int j, int size)
{
	best_possible.x = i;
	best_possible.y = j;
	best_possible.size = size;
	return (best_possible);
}

int	ft_square_fits(int **obs, int i, int j, int size)
{
	if (size > 1)
		size = size - 1;
	if (i - 1 < 0 && j - 1 < 0)
	{
		if (obs[i + size][j + size] == 0)
			return (1);
	}
	else if (i - 1 < 0)
	{
		if (obs[i + size][j + size] - obs[i + size][j - 1] == 0)
			return (1);
	}
	else if (j - 1 < 0)
	{
		if (obs[i + size][j + size] - obs[i - 1][j + size] == 0)
			return (1);
	}
	else
	{
		if (obs[i + size][j + size] - obs[i - 1][j + size]
				- obs[i + size][j - 1] + obs[i - 1][j - 1] == 0)
			return (1);
	}
	return (0);
}

t_bsq	ft_solve_shortener(char **m, int **obstacles_map, int i, int j)
{
	int		s;
	t_bsq	best;

	best.size = 0;
	while (m[++i])
	{
		j = -1;
		while (m[i][++j] && j + best.size <= ft_map_depth(m)
					&& i + best.size <= ft_map_length(m))
		{
			s = best.size;
			while (ft_square_fits(obstacles_map, i, j, s) && j + s
				<= ft_map_depth(m) && i + s <= ft_map_length(m))
			{
				s = s + 1;
				if (!(j + s <= ft_map_depth(m) && i + s <= ft_map_length(m)))
					break ;
			}
			if (s != 1)
				s--;
			if (s > best.size)
				best = ft_best_possible_fill(best, i, j, s);
		}
	}
	return (best);
}

t_bsq	ft_solve(char **map, char *value)
{
	int		**obstacles_map;
	t_bsq	best;

	best.size = 0;
	obstacles_map = ft_obstacle_map(map, value);
	if (!obstacles_map)
		return (best);
	best = ft_solve_shortener(map, obstacles_map, -1, 0);
	return (best);
}

void	ft_printing(char **map, char *value, int x)
{
	t_bsq	answer;
	int		i;
	int		j;

	i = -1;
	answer = ft_solve(map, value);
	while (++i < answer.size)
	{
		j = -1;
		while (++j < answer.size)
		{
			map[answer.x + i][answer.y + j] = value[2];
		}
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			ft_putchar(map[i][j]);
		ft_putchar('\n');
		if (x != 1)
			ft_putchar('\n');
	}
}
