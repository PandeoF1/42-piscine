/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:36:03 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:23:59 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_printing(int array[], int n)
{
	int		i;
	char	c;

	i = -1;
	while (++i < n)
	{
		c = array[i] + '0';
		write(1, &c, 1);
	}
	if (array[0] != 10 - n)
		write(1, ", ", 2);
}

void	ft_recursive(int array[], int n, int i)
{
	if (i == 0)
		array[i] = 0;
	else
		array[i] = array[i - 1] + 1;
	while (array[i] < 11 - n + i)
	{
		if (i == n - 1)
			ft_printing(array, n);
		else
			ft_recursive(array, n, i + 1);
		array[i] = array[i] + 1;
	}
}

void	ft_print_combn(int n)
{
	int	array[10];

	ft_recursive(array, n, 0);
}
