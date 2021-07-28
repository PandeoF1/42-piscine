/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:39:30 by tnard             #+#    #+#             */
/*   Updated: 2021/07/28 12:42:11 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_scanff(void)
{
	int		count;
	char	mini_buff;
	char	buff[5000];
	char	*str;

	count = 0;
	while (read(0, &mini_buff, 1))
		buff[count++] = mini_buff;
	buff[count] = 0;
	str = malloc((count) * sizeof(char));
	count = -1;
	while (buff[++count])
		str[count] = buff[count];
	str[count] = 0;
	return (str);
}
