/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:34:52 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:28:54 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_show(int **tab, int size)
{
	int	a;
	int	b;
	int	corner;

	corner = 1;
	a = 0 + corner;
	b = 0 + corner;
	while (a < size + 2 - corner)
	{
		while (b < size + 2 - corner)
		{
			ft_putnbr(tab[a][b++]);
			if (b < size + 2 - corner)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		b = 0 + corner;
		a++;
	}
	return ;
}
