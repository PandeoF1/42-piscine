/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 09:34:40 by tnard             #+#    #+#             */
/*   Updated: 2021/07/20 10:26:05 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

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
