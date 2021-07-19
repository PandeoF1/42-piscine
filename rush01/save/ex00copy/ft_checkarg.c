/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:14:59 by tnard             #+#    #+#             */
/*   Updated: 2021/07/17 10:15:00 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>

int	ft_check_count(int count, int size, int number)
{
	if (count == size * 4 && number <= size && number >= 1)
		return (1);
	return (0);
}

int	ft_checkarg(char *str, int size)
{
	int	n;
	int	count;
	int	number;

	n = 0;
	number = 0;
	count = 0;
	if (ft_is_num(str[n]))
	{
		while (str[n])
		{
			if (!ft_is_num(str[n]))
				n++;
			if (!ft_is_num(str[n]) || size < number || number < 0)
				return (0);
			number = 0;
			while (ft_is_num(str[n]))
			{
				number = (number * 10) + str[n] - '0';
				if (!ft_is_num(str[++n]))
					count++;
			}
		}
	}
	return (ft_check_count(count, size, number));
}
