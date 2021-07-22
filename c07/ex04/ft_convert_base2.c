/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:11:51 by tnard             #+#    #+#             */
/*   Updated: 2021/07/22 17:14:32 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	checkbase(char *base)
{
	int	i;
	int	a;

	if (ft_strlen(base) < 2)
		return (0);
	i = -1;
	while (base[++i])
	{
		a = i + 1;
		if (base[i] == '-' || base[i] == '+' || base[i] == '\t'
			|| base[i] == '\n' || base[i] == '\v' || base[i] == '\f'
			|| base[i] == '\r' || base[i] == ' ')
			return (0);
		while (base[a])
		{
			if (base[a] == base[i])
				return (0);
			a++;
		}
	}
	return (1);
}

int	isbase(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (1);
	return (0);
}

int	ci(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;
	int	negative;

	i = 0;
	nb = 0;
	negative = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			negative *= -1;
	if (!isbase(str[i], base))
		return (0);
	i = i - 1;
	while (isbase(str[++i], base))
		nb = nb * ft_strlen(base) + (ci(str[i], base) / ft_strlen(base))
			+ (ci(str[i], base) % ft_strlen(base));
	return (nb * negative);
}
