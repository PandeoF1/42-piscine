/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:36:25 by tnard             #+#    #+#             */
/*   Updated: 2021/07/28 11:20:08 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "bsq.h"

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

char	**ft_parse(char *filename, int a, int fd, int len)
{
	char	*content;
	char	**dest;

	fd = open(filename, O_RDWR);
	if (fd < 0)
		return (NULL);
	content = ft_file_read(fd, 0, 0);
	if (fd != STDIN_FILENO)
		close(fd);
	while (content[a])
		a++;
	if (content[a - 1] != '\n')
		return (NULL);
	dest = ft_split(content, '\n');
	free(content);
	a = 0;
	if (dest[a + 1])
		len = ft_strlen(dest[a + 1]);
	else
		return (NULL);
	while (dest[++a])
		if (len != ft_strlen(dest[a]))
			return (NULL);
	return (dest);
}
