/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:26:57 by tnard             #+#    #+#             */
/*   Updated: 2021/07/26 15:30:28 by tnard            ###   ########lyon.fr   */
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

int	main(int argc, char *argv[])
{
	int		n;
	int		a;
	char	**content;
	char	value[3];

	n = 0;
	a = 0;
	if (argc == 1)
		return (error());
	while (++n < argc)
	{
		content = ft_parse(argv[n], 0, 0, 0);
		if (content != NULL && ft_check_first_line(content, value))
		{
			dprintf(1, "%c\n", value[0]);
			dprintf(1, "%c\n", value[1]);
			dprintf(1, "%c\n", value[2]);
			a = 0;
			while (content[a])
				dprintf(1, "%s\n", content[a++]);
		}
		else
			error();
	}
	return (0);
}
