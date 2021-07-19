/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 08:15:54 by tnard             #+#    #+#             */
/*   Updated: 2021/07/12 09:48:37 by tnard            ###   ########lyon.fr   */
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
	while (argc > 1)
	{	
		ft_putstr(argv[--argc]);
		ft_putstr("\n");
	}
	return (0);
}
