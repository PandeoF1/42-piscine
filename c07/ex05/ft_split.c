/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 09:05:11 by tnard             #+#    #+#             */
/*   Updated: 2021/07/15 12:22:29 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

int	ft_count_str(char *str, char *to_find)
{
	int	n;
	int	i;
	int	a;
	int	count;

	count = 0;
	n = 0;
	i = 0;
	a = 0;
	if (to_find[i] == '\0')
		return (str);
	while (to_find[i])
		i++;
	while (str[n])
	{
		a = 0;
		while (str[n] && str[n++] == to_find[a++])
			if (to_find[a] == '\0')
				count++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int count;
	int n;
	int len;

	len = 0;
	n = 0;
	count = ft_count_str(str, charset);
	printf("%d", count); //todelete
	tab = malloc(sizeof(char **) * count);
	while (n <= count)
	{
		tab[n] = malloc(sizeof(char *) * 50);
		while ()

		n++;
	}

	return (tab);

}
