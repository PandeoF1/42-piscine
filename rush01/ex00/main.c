/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 09:31:21 by tnard             #+#    #+#             */
/*   Updated: 2021/07/18 18:49:16 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdlib.h>

int	error(void)
{
	ft_putstr("Error");
	ft_putchar('\n');
	return (0);
}

void	ft_destroy_tab(int **tab, int size)
{
	while (size--)
		free(tab[size]);
	free(tab);
	return ;
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
		ft_solve(tab, 1, 1, size);
		if (tab[size][size] != 0)
			ft_show(tab, size);
		else
			return (error());
		ft_destroy_tab(tab, size);
		return (0);
	}
	return (error());
}
