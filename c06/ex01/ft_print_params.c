/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 08:03:54 by tnard             #+#    #+#             */
/*   Updated: 2021/07/12 09:48:24 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		write(1, &str[n++], 1);
	return ;
}

int	main(int argc, char *argv[])
{
	int	n;

	n = 1;
	while (argc > n)
	{
		ft_putstr(argv[n++]);
		ft_putstr("\n");
	}
	return (0);
}
