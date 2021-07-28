/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:16:03 by tnard             #+#    #+#             */
/*   Updated: 2021/07/28 09:14:30 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bsq.h"

int	ft_check_b(char **content, char **value)
{
	int	a;
	int	i;
	int	n;

	a = 0;
	n = -1;
	while (content[0][a])
		a++;
	while (++n < a - 3)
		if (content[0][n] < '0' || content[0][n] > '9')
			return (0);
	(*value)[0] = content[0][n];
	(*value)[1] = content[0][n + 1];
	(*value)[2] = content[0][n + 2];
	content[0][n] = '\0';
	i = ft_atoi(content[0]);
	a = 0;
	while (content[a])
		a++;
	if (a - 1 != i)
		return (0);
	return (1);
}

int	ft_check_a(char **content, char *value)
{
	int	a;
	int	b;

	a = 1;
	b = 0;
	while (content[a])
	{
		while (content[a][b])
		{
			if (content[a][b] != value[0] && content[a][b] != value[1]
				&& content[a][b] != value[2])
				return (0);
			b++;
		}
		b = 0;
		a++;
	}
	return (1);
}
