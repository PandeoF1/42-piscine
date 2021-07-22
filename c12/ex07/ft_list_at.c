/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:50:52 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:26:29 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		if (count == nbr)
			return (begin_list);
	}
	return (begin_list);
}
