/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:57:54 by tnard             #+#    #+#             */
/*   Updated: 2021/07/25 18:53:25 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_putstr(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		ft_putchar(str[n++]);
}

void	ft_putstr_space(char *str, int a)
{
	int	n;

	n = 0;
	while (str[n])
		ft_putchar(str[n++]);
	if (a == 0)
		ft_putchar(' ');
}
