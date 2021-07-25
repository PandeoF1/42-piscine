/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:32:41 by tnard             #+#    #+#             */
/*   Updated: 2021/07/25 13:52:47 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>

void	ft_destroy(t_rush **parse, t_rush **parse_verif, char *path_to_dict)
{
	int	a;

	a = 0;
	while (parse[a])
	{
		free(parse[a]->name);
		free(parse[a]->value);
		free(parse[a]);
		a++;
	}
	free(parse);
	a = 0;
	while (parse_verif[a])
	{
		free(parse_verif[a]->name);
		free(parse_verif[a]->value);
		free(parse_verif[a]);
		a++;
	}
	free(parse_verif);
	free(path_to_dict);
}
