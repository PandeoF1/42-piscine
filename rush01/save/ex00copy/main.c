/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 09:31:21 by tnard             #+#    #+#             */
/*   Updated: 2021/07/17 09:31:22 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdlib.h>
#include <stdio.h>

int	error(void)
{
	ft_putstr("Error");
	ft_putchar('\n');
	return (0);
}

int	main(int argc, char *argv[])
{
	int	size;
	int	**tab;

	tab = NULL;
	size = 4;
	if (argc != 2)
		return (error());
	if (!ft_checkarg(argv[1], size))
		return (error());
	tab = ft_init(size, argv[1]);
	if (tab != NULL)
	{
		node tree;
		ft_complete_condition(tab, size, size + 2);
		int **grid = ft_clone_grid(tab,size);
		ft_init_grid_node(&tree, grid, size);
		ft_generate_all_childs(&tree);
		ft_show(tree.grid, size);
		//ft_complete_condition(tab, size, size + 2);
		//ft_complete_condition(tab, 3, size + 2);
		if (ft_check(tab, size))
		{	
			ft_solve(tab, size);
			//Zft_show(tab, size);
			return (0);
		}
	}
	return (error());
}
