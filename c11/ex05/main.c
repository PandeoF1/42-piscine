/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:25:03 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:26:07 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

#include <unistd.h>

int	main(int ac, char *av[])
{
	int	i;

	if (ac != 4)
		return (0);
	i = 0;
	while (av[2][i])
		i++;
	if ((av[2][0] == '/' || av[2][0] == '%') && ft_atoi(av[3]) == 0)
	{
		if (av[2][0] == '/')
			write(1, "Stop : division by zero\n", 24);
		if (av[2][0] == '%')
			write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	if (!(av[2][0] == '+' || av[2][0] == '-'
		|| av[2][0] == '/' || av[2][0] == '%') || i != 1)
	{
		write(1, "0", 1);
		return (0);
	}
	i = ft_op(ft_atoi(av[1]), av[2][0], ft_atoi(av[3]));
	ft_putnbr(i);
	ft_putchar('\n');
}
