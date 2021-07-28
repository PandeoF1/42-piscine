/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 06:07:16 by molatrec          #+#    #+#             */
/*   Updated: 2021/07/28 12:12:37 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

int	**ft_obstacle_map(char **map, char *value)
{
	int	x_max;
	int	y_max;
	int	**map_obstacles;

	x_max = ft_map_length(map) + ft_map_depth(map);
	y_max = ft_map_depth(map) + ft_map_length(map);
	map_obstacles = ft_create_map_obstacle(x_max, y_max);
	if (!map_obstacles)
		return (0);
	ft_fill_map_obstacles(map_obstacles, map, value);
	return (map_obstacles);
}
