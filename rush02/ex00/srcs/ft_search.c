/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:36:25 by tnard             #+#    #+#             */
/*   Updated: 2021/07/25 10:41:15 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>

t_rush	*ft_search_by_id(t_rush *pairs, int size, char *id)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!ft_strcmp(id, pairs[i].value))
			return (&pairs[i]);
		i++;
	}
	return (NULL);
}
