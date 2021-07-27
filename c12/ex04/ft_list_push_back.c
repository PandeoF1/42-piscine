/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:03:39 by tnard             #+#    #+#             */
/*   Updated: 2021/07/27 14:05:15 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*tmp;

	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_elem(data);
	return ;
}
