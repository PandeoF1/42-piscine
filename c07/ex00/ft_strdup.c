/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:58:37 by tnard             #+#    #+#             */
/*   Updated: 2021/07/15 14:15:34 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		n;

	n = 0;
	while (src[n])
		n++;
	ptr = malloc(sizeof(char) * (n + 1));
	if (!ptr)
		return (NULL);
	n = 0;
	while (src[n])
	{
		ptr[n] = src[n];
		n++;
	}
	ptr[n] = '\0';
	return (ptr);
}
