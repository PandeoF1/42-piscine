/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:24:15 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 12:06:10 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

void	ft_calc(int a, char op, int b)
{
	int long	calc;

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
	ft_putchar('\n');
}
