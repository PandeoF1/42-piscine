/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:39:04 by tnard             #+#    #+#             */
/*   Updated: 2021/07/21 17:28:29 by tnard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	n;

	n = 0;
	tab = malloc(sizeof(int) * length);
	if (!tab || length <= 0)
		return (NULL);
	while (n <= length)
	{
		tab[n] = f(tab[n]);
		n++;
	}
	return (tab);
}
