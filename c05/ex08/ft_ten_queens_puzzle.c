/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 14:04:31 by tnard             #+#    #+#             */
/*   Updated: 2021/07/23 14:16:33 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

void	ft_solve(char *tab, int nbq, int *tot)
{
	int	i;
	int	j;

	if (nbq == 10)
	{
		nbq = 0;
		while (nbq < 10)
			ft_putchar(tab[nbq++] + '0');
		ft_putchar('\n');
		(*tot)++;
		return ;
	}
	i = -1;
	while (++i < 10)
	{
		j = 0;
		while (j < nbq && i != tab[j] && ft_abs(tab[j] - i) != nbq - j)
			j++;
		if (j >= nbq)
		{
			tab[nbq] = i;
			ft_solve(tab, nbq + 1, tot);
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		nbq;
	char	tab[10];
	int		tot;

	nbq = 0;
	tot = 0;
	ft_solve(tab, nbq, &tot);
	return (tot);
}

int	main(void)
{
	printf("%d\n", ft_ten_queens_puzzle());
	return (0);
}
