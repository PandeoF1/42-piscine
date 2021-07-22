/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 08:52:59 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 09:24:51 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		to_up;

	i = 0;
	to_up = 1;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (to_up && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
			else if (!to_up && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + 32;
			to_up = 0;
		}
		else
			to_up = 1;
		i++;
	}
	return (str);
}
