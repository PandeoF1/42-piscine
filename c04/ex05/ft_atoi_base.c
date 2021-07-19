/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:55:16 by tnard             #+#    #+#             */
/*   Updated: 2021/07/15 09:12:53 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_char(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == base[i + 1]
			|| base[i] == ' ' || base[i] == '\n' || base[i] == '\t'
			|| base[i] == '\v' || base[i] == '\f' || base[i] == '\r')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	ft_mult(char d, char *base, int mult, int nbr)
{
	int	c;

	c = 0;
	while (base[c] != '\0')
	{
		if (d == base[c])
			return (nbr + (mult * c));
		c++;
	}
	return (nbr);
}

int	ft_check_char_double(char n, char *base)
{
	int	c;

	c = 0;
	if (n == '\n' || n == '\t' || n == '\v' || n == '\f' || n == '\r'
		|| n == ' ' || n == '+' || n == '-')
		return (-1);
	while (base[c] != '\0')
	{
		if (base[c] == n)
			return (1);
		c++;
	}
	return (0);
}

int	ft_atoi_calc(char *str, char *base, int size, int start)
{
	int	c;
	int	s;
	int	res;
	int	mult;

	c = start - 1;
	s = 1;
	res = 0;
	mult = 1;
	while (c >= 0)
	{
		if (str[c] == '-')
			s *= -1;
		if (ft_check_char_double(str[c], base))
		{
			res = ft_mult(str[c], base, mult, res);
			mult *= size;
		}
		c--;
	}
	return (res * s);
}

int	ft_atoi_base(char *str, char *base)
{
	int	size;
	int	c;

	size = 0;
	c = 0;
	if (ft_check_char(base) == 0)
		return (0);
	while (base[size] != '\0')
		size++;
	while (str[c] == '\n' || str[c] == '\t' || str[c] == '\v'
		|| str[c] == '\f' || str[c] == '\r' || str[c] == ' '
		|| str[c] == '-' || str[c] == '+')
		c++;
	while (str[c] >= '0' && str[c] <= '9')
		c++;
	return (ft_atoi_calc(str, base, size, c));
}
