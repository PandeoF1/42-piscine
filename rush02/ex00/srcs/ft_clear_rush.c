/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_rush.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 11:31:48 by tnard             #+#    #+#             */
/*   Updated: 2021/07/25 09:38:47 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>

void	ft_clear_rush(t_rush *this)
{
	free(this->value);
	free(this->name);
}
