/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:54:31 by tnard             #+#    #+#             */
/*   Updated: 2021/07/23 13:42:03 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list **begin_list)
{
	t_list	*a;
	t_list	*b;

	a = 0;
	while (*begin_list)
	{
		b = (*begin_list)->next;
		(*begin_list)->next = a;
		a = *begin_list;
		*begin_list = b;
	}
	*begin_list = a;
}
