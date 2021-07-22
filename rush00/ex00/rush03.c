/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 09:45:14 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:28:39 by tnard            ###   ########lyon.fr   */
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
		if (i == x && x != 1 && (j == 1 || j == y))
			ft_putchar('C');
		else if (i == 1 && (j == 1 || j == y))
			ft_putchar('A');
		else if (i == 1 || i == x || j == 1 || j == y)
			ft_putchar('B');
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
