/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:24:15 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:26:04 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"
#include <unistd.h>

int	ft_op(int val1, char op, int val2)
{
	if (op == '+')
		return (val1 + val2);
	if (op == '-')
		return (val1 - val2);
	if (op == '/')
		return (val1 / val2);
	if (op == '%')
		return (val1 % val2);
	return (0);
}
