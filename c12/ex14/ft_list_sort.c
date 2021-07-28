/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:47:52 by tnard             #+#    #+#             */
/*   Updated: 2021/07/28 17:18:07 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap_list(t_list	**a, t_list	**b)
{
	void	*tmp;

	tmp = (*a)->data;
	(*a)->data = (*b)->data;
	(*b)->data = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;
	t_list	*current;
	int		reset;

	reset = 1;
	if (!(*begin_list) || !(*begin_list)->next)
		return ;
	while (reset)
	{
		reset = 0;
		tmp = *begin_list;
		current = tmp->next;
		while (current)
		{
			if (cmp(tmp->data, current->data) > 0)
			{
				ft_swap_list(&tmp, &current);
				reset = 1;
			}
			tmp = tmp->next;
			current = current->next;
		}
	}
}
