/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:36:25 by tnard             #+#    #+#             */
/*   Updated: 2021/07/25 18:59:11 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>
#include <stdio.h>

int	error(void)
{
	ft_putstr("Error\n");
	return (0);
}

int	dict_error(void)
{
	ft_putstr("Dict Error\n");
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

int	ft_parselen(t_rush **parse)
{
	int	n;

	n = 0;
	while (parse[n])
		n++;
	return (n);
}

int	main(int argc, char *argv[])
{
	char	*path_to_dict;
	t_rush	**parse;
	t_rush	**parse_verif;
	int		count;

	parse = NULL;
	path_to_dict = ft_strdup("numbers.dict");
	if (argc == 3)
		path_to_dict = ft_strdup(argv[1]);
	else if (argc == 2)
		path_to_dict = ft_strdup("numbers.dict");
	else
		return (error());
	if (ft_checkarg(argv[argc - 1]))
		return (error());
	parse = ft_parse(path_to_dict, 0, 0);
	parse_verif = ft_parse("ref.dict", 0, 0);
	if (parse == NULL || ft_is_valid_file(parse, parse_verif)
		|| parse_verif == NULL)
		return (dict_error());
	count = ft_parselen(parse);
	ft_print_litteral_nu(argv[argc - 1], parse, count, 0);
	ft_destroy(parse, parse_verif, path_to_dict);
	ft_putchar('\n');
	return (0);
}
