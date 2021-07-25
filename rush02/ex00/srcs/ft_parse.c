/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:36:25 by tnard             #+#    #+#             */
/*   Updated: 2021/07/25 18:15:00 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "rush.h"

char	*ft_file_read(int fd, int size, int len)
{
	char	buf[2048];
	char	*value;
	char	*tmp;

	value = malloc(sizeof(char));
	if (!value)
		return (NULL);
	len = read(fd, buf, 2048);
	while (len > 0)
	{
		tmp = malloc((size + len + 1) * sizeof(char));
		if (!tmp)
			break ;
		tmp = ft_strncpy(tmp, value, size);
		free(value);
		ft_strncpy(tmp + size, buf, len);
		value = tmp;
		size += len;
		value[size] = '\0';
		len = read(fd, buf, 2048);
	}
	if (len)
		free(value);
	return (value);
}

int	ft_strlen_content(const char *str, int n)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	if (n == 1)
	{
		while (str[i] && str[i] <= '9' && str[i] >= '0')
			i++;
		return (i);
	}
	else if (n == 1)
	{
		while (str[a] && str[a] != ':')
			a++;
		a++;
		while (str[a] && str[a] == ' ')
			a++;
		while (str[a] && str[a + i] != '\n')
			i++;
		return (i);
	}
	return (i);
}

char	*ft_explode(char *content, int n, int a, int b)
{
	char	*test;

	test = malloc(sizeof(char) * ft_strlen_content(content, n) + 1);
	if (!test)
		return (NULL);
	if (n == 1)
	{
		while (content[a] && content[a] <= '9' && content[a] >= '0')
			test[b++] = content[a++];
	}
	else if (n == 0)
	{
		while (content[a] && content[a] != ':')
			a++;
		a++;
		while (content[a] && content[a] == ' ')
			a++;
		while (content[a] && content[a] != '\n')
			test[b++] = content[a++];
	}
	test[b] = '\0';
	return (test);
}

t_rush	**ft_parse(char *filename, int a, int fd)
{
	t_rush	**parse;
	char	*content;
	char	**dest;

	fd = open(filename, O_RDWR);
	if (fd < 0)
		return (NULL);
	content = ft_file_read(fd, 0, 0);
	if (fd != STDIN_FILENO)
		close(fd);
	dest = ft_split(content, '\n');
	while (dest[a])
		a++;
	parse = malloc(sizeof(t_rush *) * a + 10);
	if (!parse)
		return (NULL);
	a = -1;
	while (dest[++a])
	{
		parse[a] = malloc(sizeof(t_rush));
		if (ft_is_valid_line(dest[a]) == 0 || !parse || ft_init(parse[a],
				ft_explode(dest[a], 1, 0, 0), ft_explode(dest[a], 0, 0, 0)))
			return (NULL);
	}
	return (parse);
}
