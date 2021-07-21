/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 09:34:40 by tnard             #+#    #+#             */
/*   Updated: 2021/07/20 10:26:05 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

void	ft_calc(int a, char op, int b)
{
	int	calc;

	calc = 0;
	if (op == '+')
		calc = a + b;
	if (op == '-')
		calc = a - b;
	if (op == '*')
		calc = a * b;
	if (op == '/')
	{
		if (b == 0)
			return (ft_putstr("Stop : division by zero\n"));
		calc = a / b;
	}
	if (op == '%')
	{
		if (b == 0)
			return (ft_putstr("Stop : modulo by zero\n"));
		calc = a % b;
	}
	ft_putnbr(calc);
}
