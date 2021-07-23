/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:47:52 by tnard             #+#    #+#             */
/*   Updated: 2021/07/23 09:39:28 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list,
void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*to_free;

	while (*begin_list)
	{
		if (begin_list == 0 || (*begin_list)->next == 0)
			return ;
		if ((*cmp)((*begin_list)->next->data, data_ref) == 0)
		{
			to_free = (*begin_list)->next;
			(*begin_list)->next = to_free->next;
			(*free_fct)(to_free->data);
			free(to_free);
		}
		*begin_list = (*begin_list)->next;
	}
}
