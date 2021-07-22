/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:55:16 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:25:07 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (base[i])
	{
		if (ft_strlen(base) < 2)
			return (0);
		if (base[i] == '-' || base[i] == '+'
			|| (base[i] < 32 || base[i] > 126) || base[i] == ' '
			|| base[i] == '\n' || base[i] == '\r' || base[i] == '\v'
			|| base[i] == '\t' || base[i] == '\f')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_inside(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int			i;
	int			neg;
	long int	res;

	i = 0;
	res = 0;
	neg = 1;
	if (!check_base(base))
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (is_inside(str[i], base) != -1)
	{
		res = (res * ft_strlen(base)) + (is_inside(str[i], base));
		i++;
	}
	return (res * neg);
}
