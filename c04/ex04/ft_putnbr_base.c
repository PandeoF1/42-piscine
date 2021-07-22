/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:44:50 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:25:08 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_base(char *base, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (base[n])
		if (base[n++] == c)
			i++;
	if (i >= 2)
		return (0);
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_strprint(unsigned int n, char *base, unsigned int size)
{
	if (n > size - 1)
	{
		ft_strprint(n / size, base, size);
		n %= size;
	}
	ft_putchar(base[n]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	n;

	n = 0;
	while (base[n])
	{
		if ((base[n] == '-' || base[n] == '+' || !ft_check_base(base, base[n])))
			return ;
		n++;
	}
	if (n < 2)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_strprint(-nbr, base, n);
	}
	else
		ft_strprint(nbr, base, n);
}
