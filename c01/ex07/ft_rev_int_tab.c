/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:23:00 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:24:12 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	swap;
	int	mi;
	int	i;

	i = 0;
	mi = size - 1;
	while (i < (size / 2))
	{
		swap = tab[i];
		tab[i] = tab[mi];
		tab[mi] = swap;
		i++;
		mi--;
	}
}
