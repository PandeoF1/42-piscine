/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:44:48 by jufabreg          #+#    #+#             */
/*   Updated: 2021/07/22 13:10:27 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	check_base(char c, char *str);
int	ft_atoi_base(char *str, char *base);
int	count_letter(long nbr, char *base);

char	*ft_itoa_base(long nb, char *base)
{
	char	*res;
	int		i;
	int		l;
	int		trig;

	trig = 1;
	l = ft_strlen(base);
	i = count_letter(nb, base);
	if (nb < 0)
	{
		nb = -nb;
		trig++;
	}
	res = (char *)malloc(sizeof(char) * i + trig);
	if (!res)
		return (NULL);
	res[i] = '\0';
	while (i-- > 0)
	{
		res[i] = base[nb % l];
		nb /= l;
	}
	if (trig == 2)
		res[0] = '-';
	return (res);
}

int	ft_is_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (base[i])
	{
		while (base[i] != base[j] && base[j])
		{
			j++;
		}
		if (base[i] == base[j])
			return (0);
		i++;
		j = i + 1;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	ft_is_in_base(char *nbr, char *base_from)
{
	int		n;
	int		i;
	int		count;

	n = 0;
	i = 0;
	count = 0;
	while (nbr[n] == ' ' || (nbr[n] <= 13 && nbr[n] >= 9))
		n++;
	while (nbr[n] == '+' || nbr[n] == '-')
		n++;
	while (nbr[n])
	{
		while (base_from[i])
		{
			if (nbr[n] == base_from[i++])
				count++;
		}
		n++;
	}
	if (count == 1)
		return (1);
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nb;
	char	*toa;

	if (!ft_is_base(base_from) || !ft_is_base(base_to)
		|| !ft_is_in_base(nbr, base_from))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	toa = ft_itoa_base(nb, base_to);
	return (toa);
}
