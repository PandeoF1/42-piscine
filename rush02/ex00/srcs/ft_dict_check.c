/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 09:42:58 by tnard             #+#    #+#             */
/*   Updated: 2021/07/25 10:58:21 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_is_valid_line(char	*src)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (src[i])
		i++;
	while (src[n] && (src[n] <= '9' && src[n] >= '0'))
		n++;
	while (src[n] && (src[n] == ' '))
		n++;
	if (src[n] != ':')
		return (0);
	n++;
	while (src[n] && (src[n] == ' '))
		n++;
	while (src[n] && (src[n] >= 32))
		n++;
	if (n == i && src[n - 1] != ' ')
		return (1);
	return (0);
}

int	ft_is_valid_file(t_rush	**parse)
{
	int	n;

	n = 0;
	while (parse[n])
	{
		n++;
	}
	return (0);
}