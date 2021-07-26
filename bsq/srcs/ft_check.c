/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:16:03 by tnard             #+#    #+#             */
/*   Updated: 2021/07/26 17:25:07 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check_first_line(char **content, char **value)
{
	int	a;
	int	n;

	a = 0;
	n = -1;
	while (content[0][a])
		a++;
	while (++n < a - 3) //4 = 3 + le char avant ou t'arrive
		if (content[0][n] < '0' || content[0][n] > '9')
			return (0);
	(*value)[0] = content[0][n];
	(*value)[1] = content[0][n + 1];
	(*value)[2] = content[0][n + 2];
	return (1);
}

int	ft_check_file(char **content, char *value)
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