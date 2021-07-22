/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:03:42 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:24:58 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	n;
	int	a;

	n = 0;
	a = 0;
	while (dest[n])
		n++;
	while (src[a] && nb-- != 0)
		dest[n++] = src[a++];
	dest[n] = '\0';
	return (dest);
}
