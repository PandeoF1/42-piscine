/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 09:34:40 by tnard             #+#    #+#             */
/*   Updated: 2021/07/20 09:34:41 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	n;
	int	revert;

	n = 0;
	revert = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	revert = 0;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			revert = 1 - revert;
	n = 0;
	while (*str >= '0' && *str <= '9')
		n = n * 10 + *str++ - '0';
	if (revert)
		n *= -1;
	return (n);
}

void	ft_putstr(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		write (1, &str[n++], 1);
	return ;
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
		ft_putstr("-");
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putstr(nb % 10 + '0';
}

void	ft_calc(int a, char op, int b)
{
	int	calc;

	calc = 0;
	if (op == '+')
		calc = a + b;
	ft_putnbr(calc);
}

int	main(int argc, char *argv[])
{
	int	n;

	n = 0;
	if (argc != 4)
		return (1);
	while (argv[2][n])
		n++;
	if ((argv[2][0] == '+' || argv[2][0] == '-'
		|| argv[2][0] == '/' || argv[2][0] == '*'
		|| argv[2][0] == '%') && n == 1)
	{
		ft_calc(ft_atoi(argv[1]), argv[2][0], ft_atoi(argv[3]));
	}
	else
		return (1);
	return (0);
}
