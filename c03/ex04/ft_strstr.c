/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:23:21 by tnard             #+#    #+#             */
/*   Updated: 2021/07/10 18:29:42 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	n;
	int	i;
	int	a;

	n = 0;
	i = 0;
	a = 0;
	if (to_find[i] == '\0')
		return (str);
	while (to_find[i])
		i++;
	while (str[n])
	{
		a = 0;
		while (str[n] && str[n++] == to_find[a++])
		{
			if (to_find[a] == '\0')
				return (&str[n - a]);
		}
	}
	return (0);
}
