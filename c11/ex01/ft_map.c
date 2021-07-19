/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:39:04 by tnard             #+#    #+#             */
/*   Updated: 2021/07/19 14:39:05 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*tab;
	int	n;

	n = 0;
	tab = malloc(sizeof(int) * length);
	if (!tab || length <= 0)
		return (NULL);
	while (n <= length)
		tab[length] = f(tab[n++]);
	return (tab);
}
