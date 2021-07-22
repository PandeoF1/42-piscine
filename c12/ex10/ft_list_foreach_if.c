/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:10:33 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:26:37 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
void *data_ref, int (*cmp)())
{
	if (!begin_list)
		return ;
	if (!cmp(begin_list->data, data_ref))
		f(begin_list->data);
	ft_list_foreach_if(begin_list->next, f, data_ref, cmp);
	return ;
}
