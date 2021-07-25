/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:36:25 by tnard             #+#    #+#             */
/*   Updated: 2021/07/25 17:54:56 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>

t_rush	*ft_search_by_id_parse(t_rush **parse, char *id)
{
	int	i;

	i = 0;
	while (parse[i])
	{
		if (!ft_strcmp(id, parse[i]->value))
			return (parse[i]);
		i++;
	}
	return (NULL);
}

t_rush	*ft_search_by_id(t_rush **pairs, int size, char *id)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (!ft_strcmp(id, pairs[i]->value))
			return (pairs[i]);
		i++;
	}
	return (NULL);
}
