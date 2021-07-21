/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:13:12 by tnard             #+#    #+#             */
/*   Updated: 2021/07/21 16:13:12 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen(int long n, int long lenbase)
{
	if (n < lenbase)
		return (1);
	return (1 + ft_nbrlen(n / lenbase, lenbase));
}

int	long	ft_strlen(char *str)
{
	int long	index;

	index = 0;
	while (str[index])
	{
		index++;
	}
	return (index);
}

int	ft_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_verifbase(char *base)
{
	int	index;
	int	j;

	j = 0;
	index = 0;
	while (base[index])
	{
		if (base[index] == '+' || base[index] == '-'
			|| (base[index] >= 9 && base[index] <= 13) || base[index] == 32)
			return (0);
		while (j < index)
		{
			if (base[j] == base[index])
				return (0);
			j++;
		}
		j = 0;
		index++;
	}
	if (index < 2)
		return (0);
	else
		return (index);
}

char	*ft_clean(char *str, char *base)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_index(str[i], base))
			return (&str[i]);
		i++;
	}
	return ("");
}
