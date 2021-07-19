/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:53:11 by tnard             #+#    #+#             */
/*   Updated: 2021/07/12 11:32:09 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 1)
	{
		return (!power);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}
