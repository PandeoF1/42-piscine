/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:17:32 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:26:13 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_strswap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	size;
	int	i;

	size = 0;
	while (tab[size])
		size++;
	while (size-- > 0)
	{
		i = 0;
		while (i++ < size)
			if (cmp(tab[i - 1], tab[i]) > 0)
				ft_strswap(&tab[i - 1], &tab[i]);
	}
}
