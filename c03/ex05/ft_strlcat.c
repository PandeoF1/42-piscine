/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:11:14 by tnard             #+#    #+#             */
/*   Updated: 2021/07/14 17:13:07 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	srclen;
	unsigned int	destlen;

	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	destlen = 0;
	while (dest[destlen])
		destlen++;
	i = 0;
	while (src[i] && destlen + i < (size - 1))
	{
		dest[i + destlen] = src[i];
		i++;
	}
	if (i < size)
		dest[destlen + i] = '\0';
	if (destlen > size)
		return (srclen + size);
	return (destlen + srclen);
}
