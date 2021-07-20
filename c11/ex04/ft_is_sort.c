/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 09:12:32 by tnard             #+#    #+#             */
/*   Updated: 2021/07/20 09:12:33 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	r;
	int	r2;

	i = 1;
	r = f(tab[i - 1], tab[i]);
	while (i < length && !(r))
	{
		i++;
		r = f(tab[i - 1], tab[i]);
	}
	while (i < length)
	{
		r2 = f(tab[i - 1], tab[i]);
		if ((r < 0 && r2 > 0) || (r > 0 && r2 < 0))
			return (0);
		i++;
	}
	return (1);
}
