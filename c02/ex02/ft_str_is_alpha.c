/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 07:24:04 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:24:21 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	n;
	int	alpha;

	n = 0;
	alpha = 1;
	while (str[n])
	{
		if ((str[n] >= 65 && str[n] <= 90) || (str[n] >= 97 && str[n] <= 122))
			alpha = 1;
		else
			return (0);
		n++;
	}
	return (alpha);
}
