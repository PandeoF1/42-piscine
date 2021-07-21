/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:17:32 by tnard             #+#    #+#             */
/*   Updated: 2021/07/21 17:23:59 by tnard            ###   ########.fr       */
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
