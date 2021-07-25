/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:36:25 by tnard             #+#    #+#             */
/*   Updated: 2021/07/25 10:23:22 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>

int	error(void)
{
	ft_putstr("Error\n");
	return (0);
}

int	ft_checkarg(char *argv)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (argv[n])
		n++;
	while (argv[i] && argv[i] <= '9' && argv[i] >= '0')
		i++;
	if (n == i && n != 0)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	char	*path_to_dict;
	t_rush	**parse;
	int		error_value;

	parse = NULL;
	path_to_dict = ft_strdup("numbers.dict");
	if (argc == 3)
	{
		path_to_dict = ft_strdup(argv[1]);
		if (ft_checkarg(argv[2]))
			return (error());
	}
	else if (argc == 2)
	{
		path_to_dict = ft_strdup("numbers.dict");
		if (ft_checkarg(argv[1]))
			return (error());
	}
	else
		return (error());
	error_value = ft_parse(parse, path_to_dict, 0);
	if (error_value == -1)
		ft_putstr("Dict Error\n");
	return (0);
}
