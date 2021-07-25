/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 09:42:58 by tnard             #+#    #+#             */
/*   Updated: 2021/07/25 13:27:42 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>
#include <stdio.h>

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

int	ft_count_value(t_rush **parse, char *id)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (parse[i])
	{
		if (!ft_strcmp(id, parse[i]->value))
			count++;
		i++;
	}
	return (count);
}

int	ft_is_valid_file(t_rush	**parse, t_rush **parse_verif)
{
	int		a;
	int		b;
	int		count;
	t_rush	*tmp;

	a = 0;
	b = 0;
	count = 0;
	while (parse_verif[a])
	{
		while (parse[b])
		{
			tmp = ft_search_by_id_parse(parse, parse_verif[a]->value);
			count = ft_count_value(parse, parse_verif[a]->value);
			if (tmp == NULL || count >= 2)
				return (1);
			b++;
		}
		b = 0;
		a++;
	}
	free(tmp);
	return (0);
}
