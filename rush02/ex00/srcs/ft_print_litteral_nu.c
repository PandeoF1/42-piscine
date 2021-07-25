/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_litteral_nu.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:58:55 by vsandre           #+#    #+#             */
/*   Updated: 2021/07/25 18:33:49 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>

char	*ft_strndup(char *src, int nb)
{
	char	*ptr;
	int		n;

	n = 0;
	while (src[n])
		n++;
	ptr = malloc(sizeof(char) * (nb + 1));
	if (!ptr)
		return (NULL);
	n = 0;
	while (src[n] && n < nb)
	{
		ptr[n] = src[n];
		n++;
	}
	ptr[n] = '\0';
	return (ptr);
}

t_rush	*find_max_of(char *number, t_rush **map, int map_size)
{
	int	number_size;
	int	i;
	int	max_len;
	int	max_len_index;

	number_size = ft_strlen(number);
	i = -1;
	max_len = 0;
	max_len_index = -1;
	while (++i < map_size)
	{
		if (ft_strlen(map[i]->value) <= number_size
			&& ft_strlen(map[i]->value) > max_len)
		{
			max_len = ft_strlen(map[i]->value);
			max_len_index = i;
		}
	}
	if (max_len_index >= 0)
		return (map[max_len_index]);
	return (NULL);
}

t_rush	*find_max_of_dualnu(char *number, t_rush **map, int map_size)
{
	int		i;
	int		index_max;
	char	max_value[2];

	i = -1;
	index_max = -1;
	ft_strcpy(max_value, "00");
	while (++i < map_size - 1)
	{
		if (!ft_strcmp(number, map[i]->value))
			return (map[i]);
		if (ft_strlen(map[i]->value) == 2)
		{
			if (ft_strcmp(map[i]->value, max_value) >= 1
				&& map[i]->value[0] <= number[0]
				&& map[i]->value[1] <= number[1])
			{
				ft_strcpy(max_value, map[i]->value);
				index_max = i;
			}
		}
	}
	if (index_max >= 0)
		return (map[index_max]);
	return (NULL);
}

int	ft_countz_before(char *number)
{
	int	i;

	i = 0;
	while (number[i] && number[i] == '0')
		i++;
	return (i);
}

void	ft_print_litteral_nu(char *str_n, t_rush **map, int map_size)
{
	int		trpos;
	int		str_nu_size;
	char	*str_nu_trunced;
	int		len_of_max;

	str_nu_size = ft_strlen(str_n);
	if (str_nu_size == 1)
		ft_putstr(ft_search_by_id(map, map_size, str_n)->name);
	if (str_nu_size == 2)
	{
		ft_putstr(find_max_of_dualnu(str_n, map, map_size)->name);
		if (ft_strcmp(find_max_of_dualnu(str_n, map, map_size)->value, str_n)
			!= 0)
		{
			ft_putchar(' ');
			ft_print_litteral_nu(str_n + 1, map, map_size);
		}
	}
	if (str_nu_size > 2)
	{
		len_of_max = ft_strlen(find_max_of(str_n, map, map_size)->value);
		trpos = str_nu_size - len_of_max;
		str_nu_trunced = ft_strndup(str_n, trpos + 1);
		ft_print_litteral_nu(str_nu_trunced, map, map_size);
		ft_putchar(' ');
		ft_putstr(find_max_of(str_n, map, map_size)->name);
		if (ft_strcmp(find_max_of_dualnu(str_n, map, map_size)->value, str_n)
			!= 0)
		{
			ft_putchar(' ');
			trpos += ft_countz_before(str_n + trpos + 1);
			ft_print_litteral_nu(str_n + trpos + 1, map, map_size);
		}
	}
}
