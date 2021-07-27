/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:26:57 by tnard             #+#    #+#             */
/*   Updated: 2021/07/27 11:43:13 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <stdio.h>

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
	int		n;
	int		a;
	char	**content;
	char	*value;

	n = 0;
	a = 0;
	value = malloc(sizeof(char) * 3);
	if (!value || argc == 1)
		return (error());
	while (++n < argc)
	{
		content = ft_parse(argv[n], 0, 0, 0);
		if (content != NULL && ft_check_first_line(content, &value)
			&& ft_check_file(content, value)) //value[0] = '.' value[0] = 'o' value[0] = 'x' 
		{
			ft_printing(&content[1]);
		}
		else
			map_error();
	}
	free(value);
	return (0);
}
