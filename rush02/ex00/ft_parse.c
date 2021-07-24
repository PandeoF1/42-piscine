/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:36:25 by tnard             #+#    #+#             */
/*   Updated: 2021/07/24 18:19:28 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
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

char	*ft_explode(char *content, int n)
{
	char	*test;
	int		a;
	int		b;

	test = malloc(sizeof(char) * ft_strlen(content) + 1);
	if (!test)
		return (NULL);
	a = 0;
	b = 0;
	if (n == 1)
	{
		while (content[a] && content[a] <= '9' && content[a] >= '0')
		{
			test[b] = content[a];
			b++;
			a++;
		}
	}
	else if (n == 0)
	{
		while (content[a] && content[a] != ':')
			a++;
		while (content[a] && content[a] >= 33)
			a++;
		while (content[a])
		{
			test[b] = content[a];
			b++;
			a++;
		}
	}
	test[b] = '\0';
	dprintf(1, "%s - %d\n", test, n);
	return (test);
}

int	ft_parse(t_rush	**parse, char *filename)
{
	int		fd;
	char	*content;
	char	**content_explode;
	int		a;
	int		b;

	a = 0;
	b = 0;
	fd = open(filename, O_RDWR);
	if (fd < 0)
		return (-1);
	content = ft_file_read(fd, 0, 0);
	if (fd != STDIN_FILENO)
		close(fd);
	dprintf(1, "%s", content);
	dprintf(1, "\n------\n");
	content_explode = ft_split(content, '\n');
	while (content_explode[a])
		a++;
	parse = malloc(sizeof(t_rush *) * a + 1);
	if (!parse)
		return (-1);
	a = 0;
	while (content_explode[a])
	{
		parse[a] = malloc(sizeof(t_rush));
		if (!parse)
			return (-1);
		ft_init_rush(parse[a], ft_explode(content_explode[a], 1),
			ft_explode(content_explode[a], 0));
		a++;
	}
	a = 0;
	while (content_explode[a])
	{
		dprintf(1, "%d", a);
		dprintf(1, " | ");
		dprintf(1, "%s", parse[a]->value);
		dprintf(1, " | ");
		dprintf(1, "%s\n", parse[a]->name);
		a++;
	}
	return (0);
}

int	main(void)
{
	char	file[50];
	t_rush	**parse;
	int		error;

	ft_strcpy(file, "numbers.dict");
	error = ft_parse(parse, file);
	if (error == -1)
		ft_putstr("Dict Error\n");
}
