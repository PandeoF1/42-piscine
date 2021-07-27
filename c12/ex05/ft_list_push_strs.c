/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:33:19 by tnard             #+#    #+#             */
/*   Updated: 2021/07/27 14:10:45 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	if (*begin_list)
		elem->next = *begin_list;
	*begin_list = elem;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*begin;

	begin = 0;
	i = 0;
	while (i < size)
		ft_list_push_front(&begin, strs[i++]);
	return (begin);
}
