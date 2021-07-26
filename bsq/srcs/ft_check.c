/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:16:03 by tnard             #+#    #+#             */
/*   Updated: 2021/07/26 15:32:51 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check_first_line(char **content, char *value)
{
	int	a;
	int	n;

	a = 0;
	n = -1;
	while (content[0][a])
		a++;
	while (++n < a - 3)
		if (content[0][n] >= '9' || content[0][n] <= '0')
			return (1);
	dprintf(1, "--%d--", n);
	value[0] = content[0][n++];
	value[1] = content[0][n++];
	value[2] = content[0][n];
	return (0);
}
