/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:26:57 by tnard             #+#    #+#             */
/*   Updated: 2021/07/27 18:21:22 by tnard            ###   ########lyon.fr   */
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

int	map_error(void)
{
	ft_putstr("map error\n");
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
			ft_printing(&a[1]);
		else
			map_error();
	}
	while (++g_n < argc)
	{
		a = ft_parse(argv[g_n], 0, 0, 0);
		if (a != NULL && ft_check_b(a, &value) && ft_check_a(a, value))
			ft_printing(&a[1]);
		else
			map_error();
	}
	free(value);
	return (0);
}
