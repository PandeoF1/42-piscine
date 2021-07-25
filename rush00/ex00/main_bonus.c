/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 09:26:58 by tnard             #+#    #+#             */
/*   Updated: 2021/07/25 16:53:05 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
int		ft_atoi(char *str);

int	main(int argc, char *argv[])
{
	if (argc == 3)
		rush(atoi(argv[1]), atoi(argv[2]));
	else
		rush(5, 5);
	return (0);
}
