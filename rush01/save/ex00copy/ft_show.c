/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:34:52 by tnard             #+#    #+#             */
/*   Updated: 2021/07/17 17:34:52 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_show(int **tab, int size)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < size + 2)
	{
		while (b < size + 2)
		{
			ft_putchar(' ');
			ft_putnbr(tab[a][b++]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		b = 0;
		a++;
	}
	return ;
}
