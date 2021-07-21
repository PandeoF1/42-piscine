/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:33:19 by tnard             #+#    #+#             */
/*   Updated: 2021/07/20 14:33:20 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*tmp;
	t_list	*begin;
	int		n;

	n = 0;
	while (n < size)
	{
		tmp = ft_create_elem(strs[n]);
		tmp->next = begin;
		begin = tmp;
		n++;
	}
	return (begin);
}
