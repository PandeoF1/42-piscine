/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:26:57 by tnard             #+#    #+#             */
/*   Updated: 2021/07/28 13:21:46 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <stdio.h>

int	g_n;

int	error(void)
{
	ft_putstr("Error\n");
	return (-1);
}

int	map_error(int n)
{
	write(2, "map error\n", 10);
	if (n != 1)
		write(1, "\n", 1);
	return (-1);
}

int	main(int argc, char *argv[])
{
	char	**a;
	char	*value;

	g_n = 0;
	value = malloc(sizeof(char) * 3);
	if (!value)
		return (error());
	if (argc == 1)
	{
		a = ft_split(ft_scanff(), '\n');
		if (a != NULL && ft_check_b(a, &value) && ft_check_a(a, value))
			ft_printing(&a[1], value, 1);
		else
			map_error(1);
	}
	while (++g_n < argc)
	{
		a = ft_parse(argv[g_n], 0, 0, 0);
		if (a != NULL && ft_check_b(a, &value) && ft_check_a(a, value))
			ft_printing(&a[1], value, argc - g_n);
		else
			map_error(argc - g_n);
	}
	return (0);
}
