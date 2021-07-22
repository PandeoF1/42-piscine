/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 08:05:05 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:24:23 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	n;
	int	lowercase;

	n = 0;
	lowercase = 1;
	while (str[n])
	{
		if (str[n] >= 97 && str[n] <= 122)
			lowercase = 1;
		else
			return (0);
		n++;
	}
	return (lowercase);
}
