/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 08:12:44 by tnard             #+#    #+#             */
/*   Updated: 2021/07/08 08:26:35 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	n;
	int	uppercase;

	n = 0;
	uppercase = 1;
	while (str[n])
	{
		if (str[n] >= 65 && str[n] <= 90)
			uppercase = 1;
		else
			return (0);
		n++;
	}
	return (uppercase);
}
