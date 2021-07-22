/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:15:02 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:28:52 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_getarg(char *str, int nb)
{
	int	n;
	int	count;
	int	result;

	n = 0;
	result = 0;
	count = 0;
	while (str[n])
	{
		while (!ft_is_num(str[n]))
			n++;
		while (ft_is_num(str[n]))
		{
			result = (result * 10) + str[n] - '0';
			n++;
			if (!ft_is_num(str[n]))
				count++;
			if (count == nb && (!ft_is_num(str[n])))
				return (result);
		}
		result = 0;
		n++;
	}
	return (-1);
}
