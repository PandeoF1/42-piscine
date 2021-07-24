/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:36:25 by tnard             #+#    #+#             */
/*   Updated: 2021/07/24 17:52:09 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>

int	error(void)
{
	ft_putstr("Error\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*path_to_dict;
	char	*number;

	i = 0;
	if (argc == 2 || argc == 3)
	{
		if (argc == 2)
		{
			ft_strnumber(argv[1]);
			argv[1] = number;
			//printf ("%s1\n", number);
			return (0);
		}
		else
		{
			ft_strnumber(argv[2]);
			argv[1] = path_to_dict;
			//printf("%s2\n", number);
			argv[2] = number;
			//printf("%s3\n", number);
			return (0);
		}
	}
	else
		return (error());
}
