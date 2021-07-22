/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 08:03:54 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:25:22 by tnard            ###   ########lyon.fr   */
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
