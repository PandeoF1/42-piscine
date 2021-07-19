/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 09:28:26 by tnard             #+#    #+#             */
/*   Updated: 2021/07/10 10:00:25 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int		i;
	int		j;

	i = 1;
	j = y;
	while (j >= 1 && x > 0 && y > 0)
	{
		if ((i == x && j == y) || (i == 1 && j == 1)
			|| (i == x && j == 1) || (i == 1 && j == y))
			ft_putchar('o');
		else if (j == 1 || j == y)
			ft_putchar('-');
		else if (i == 1 || x == i)
			ft_putchar('|');
		else
			ft_putchar(' ');
		if (i == x)
		{
			ft_putchar('\n');
			i = 1;
			j--;
		}
		else
			i++;
	}
}
