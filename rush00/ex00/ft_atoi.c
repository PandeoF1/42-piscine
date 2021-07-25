/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:52:08 by tnard             #+#    #+#             */
/*   Updated: 2021/07/25 17:00:26 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	result;
	int	revert;
	int	n;

	result = 0;
	n = 0;
	revert = 1;
	while ((str[n] >= 9 && str[n] <= 13) || str[n] == ' ')
		n++;
	while (str[n] == '-' || str[n] == '+')
		if (str[n++] == '-')
			revert *= -1;
	result = 0;
	while (str[n] >= '0' && str[n] <= '9')
		result = result * 10 + str[n++] - '0';
	return (result * revert);
}
