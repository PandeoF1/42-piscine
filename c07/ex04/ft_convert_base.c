/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:13:07 by tnard             #+#    #+#             */
/*   Updated: 2021/07/21 16:13:08 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int			ft_nbrlen(int long n, int long lenbase);
int			ft_index(char c, char *base);
int			ft_verifbase(char *base);
int long	ft_strlen(char *str);
char		*ft_clean(char *str, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int	neg;
	int	i;
	int	result;
	int	lenbase;

	neg = 1;
	lenbase = ft_verifbase(base);
	result = 0;
	i = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	str = ft_clean(str, base);
	while (ft_index(str[i], base) >= 0)
	{
		result = ft_index(str[i], base) + result * lenbase;
		i++;
	}
	return (neg * result);
}

char	*ft_putnbr_base_(char *result, int k, int long nb, char *base)
{
	int	sizenb;
	int	lenbase;

	lenbase = ft_strlen(base);
	sizenb = ft_nbrlen(nb, lenbase);
	if (k)
		result[0] = '-';
	while (sizenb + k > k)
	{
		result[sizenb - 1 + k] = base[nb % lenbase];
		nb = nb / lenbase;
		sizenb--;
	}
	return (result);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int long	nb;
	int long	lenbase;
	char		*result;
	int			sizenb;
	int			k;

	k = 0;
	lenbase = ft_strlen(base);
	nb = nbr;
	result = 0;
	sizenb = ft_nbrlen(nb, lenbase);
	if (nb < 0)
	{
		k++;
		nb *= -1;
	}
	result = malloc(sizeof(char) * (sizenb + k) + 1);
	if (!(result))
		return (NULL);
	result[sizenb + k] = '\0';
	return (ft_putnbr_base_(result, k, nb, base));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;

	if (ft_verifbase(base_from) == 0 || ft_verifbase(base_to) == 0)
		return (0);
	result = ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to);
	return (result);
}
