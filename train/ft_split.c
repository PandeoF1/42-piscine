/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 09:23:24 by tnard             #+#    #+#             */
/*   Updated: 2021/07/29 13:58:10 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_countword(char *content)
{
	int	n;
	int	count;

	n = 0;
	count = 0;
	while (content[n])
	{
		if (content[n] != ' ' && content[n + 1] != '\0')
			count++;
		while (content[n] && content[n] != ' ')
			n++;
		n++;
	}
	return (count);
}

int	ft_nextword(char *content, int n)
{
	while (content[n] && content[n] != ' ')
		n++;
	return (n);
}

int	ft_strlen(char *content)
{
	int	n;

	n = 0;
	while (content[n])
		n++;
	return (n);
}

char	**ft_split(char *content)
{
	char	**split;
	int		n;
	int		a;
	int		b;

	n = 0;
	a = 0;
	b = 0;
	split = malloc(sizeof(char *) * ft_countword(content) + 1);
	while (a < ft_countword(content))
	{
		printf("uwu %d\n", a);
		while (content[n] && content[n] == ' ')
			n++;
		split[a] = malloc(sizeof(char) * ft_nextword(content, n) + 1);
		while (content[n] && content[n] != ' ')
			split[a][b++] = content[n++];
		split[a][b] = '\0';
		b = 0;
		a++;
	}
	split[n] = 0;
	return (split);
}

int	main(void)
{
	char 	test[] = "  0        1       2 3        4    5 6 7 8  9 10 11               12        13 ' j l l;k;kl;lk                                 j           ;';klhjghj";
	char	**bebou;
	int		a;

	a = 0;
	printf("\nWord : %d\n\n", ft_countword(test));
	bebou = ft_split(test);
	while (bebou[a])
	{
		printf("Word %d : %s\n", a, bebou[a]);
		a++;
	}
}
