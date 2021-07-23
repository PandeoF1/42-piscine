/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:47:52 by tnard             #+#    #+#             */
/*   Updated: 2021/07/23 11:21:05 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_strswap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	**save;
	t_list	**back;

	*save = *begin_list;
	*back = *begin_list;
	while (*begin_list)
	{	
		(*begin_list) = (*begin_list)->next;
		if (cmp((*back)->data, (*begin_list)->data) > 0)
		{
			ft_strswap((*back)->data, (*begin_list)->data);
			begin_list = save;
			begin_list = back;
		}
		else
			if (*back)
				(*back) = (*back)->next;
	}
}
