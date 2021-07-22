/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:50:14 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:25:41 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putstr(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		write(1, &str[n++], 1);
	write(1, "\n", 1);
	return ;
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	n;

	n = 0;
	while (par[n].str)
	{
		ft_putstr(par[n].str);
		ft_putnbr(par[n].size);
		ft_putchar('\n');
		ft_putstr(par[n].copy);
		n++;
	}
	return ;
}
