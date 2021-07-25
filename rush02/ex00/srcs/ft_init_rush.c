/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 11:31:51 by tnard             #+#    #+#             */
/*   Updated: 2021/07/25 12:36:09 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>

int	ft_init(t_rush *this, char *value, char *name)
{
	int	value_size;
	int	name_size;

	name_size = ft_strlen(name);
	value_size = ft_strlen(value);
	this->value = malloc(sizeof(char) * value_size);
	if (!this->value)
		return (1);
	ft_strcpy(this->value, value);
	this->name = malloc(sizeof(char) * name_size);
	if (!this->name)
		return (1);
	ft_strcpy(this->name, name);
	return (0);
}
