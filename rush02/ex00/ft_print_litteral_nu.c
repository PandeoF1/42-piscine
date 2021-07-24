/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_litteral_nu.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:58:55 by vsandre           #+#    #+#             */
/*   Updated: 2021/07/24 18:18:39 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
t_rush *find_max_of(char *number, t_rush *map, int map_size)
{
	int number_size;
	int i;
	int	max_len;
	int max_len_index;
	
	number_size = ft_strlen(number);
	i = -1;
	max_len = 0;
	while (++i < map_size)
	{
		if (ft_strlen(map[i].name) <= number_size && ft_strlen(map[i].name) > max_len)
		{
			max_len = ft_strlen(map[i].name);
			max_len_index = i;
		}
	}
	return (&map[max_len_index]);
}



void    ft_print_litteral_nu(char *str_nu)
{
	int i;
	int str_nu_size;

	str_nu_size = ft_strlen(str_nu);
	while(*str_nu)
	{
		
		str_nu++;
	}
}

#include <stdio.h>
int main()
{
/*	t_rush dict[32];
	t_rush	p0;
	t_rush	p1;
	t_rush	p2;
	t_rush	p3;
	t_rush	p4;
	t_rush	p5;
	t_rush	p6;
	t_rush	p7;
	t_rush	p8;
	t_rush	p9;
	t_rush	p10;
	t_rush	p11;
	t_rush	p12;
	t_rush	p13;
	t_rush	p14;
	t_rush	p15;
	t_rush	p16;
	t_rush	p17;
	t_rush	p18;
	t_rush	p19;
	t_rush	p20;
	t_rush	p30;
	t_rush	p40;
	t_rush	p50;
	t_rush	p60;
	t_rush	p70;
	t_rush	p80;
	t_rush	p90;
	t_rush	p100;
	t_rush	p1000;
	t_rush	p10000;
	t_rush	p100000;
	t_rush	p1000000;
	t_rush	p10000000;
	
	ft_init_rush(&p0, "0", "zero");
	ft_init_rush(&p1, "1", "one");
	ft_init_rush(&p2, "2", "two");
	ft_init_rush(&p3, "3", "three");
	ft_init_rush(&p4, "4", "four");
	ft_init_rush(&p5, "5", "five");
	ft_init_rush(&p6, "6", "six");
	ft_init_rush(&p7, "7", "seven");
	ft_init_rush(&p8, "8", "eight");
	ft_init_rush(&p9, "9", "nine");
	ft_init_rush(&p10, "10", "ten");
	ft_init_rush(&p11, "11", "eleven");
	ft_init_rush(&p12, "12", "twelve");
	ft_init_rush(&p13, "13", "thirteen");
	ft_init_rush(&p14, "14", "fourteen");
	ft_init_rush(&p15, "15", "fifteen");
	ft_init_rush(&p16, "16", "sixteen");
	ft_init_rush(&p17, "17", "seventeen");
	ft_init_rush(&p18, "18", "eighteen");
	ft_init_rush(&p19, "19", "nineteen");
	ft_init_rush(&p20, "20", "twenty");
	ft_init_rush(&p30, "30", "thirty");
	ft_init_rush(&p40, "40", "forty");
	ft_init_rush(&p50, "50", "fifty");
	ft_init_rush(&p60, "60", "sixty");
	ft_init_rush(&p70, "70", "seventy");
	ft_init_rush(&p80, "80", "eighty");
	ft_init_rush(&p90, "90", "ninety");
	ft_init_rush(&p100, "100", "hundred");
	ft_init_rush(&p1000, "1000", "thousand");
	ft_init_rush(&p90, "10000", "million");
	ft_init_rush(&p100, "100000", "billion");
	
	dict[0] = p0;
	dict[1] = p1;
	dict[2] = p2;
	dict[3] = p3;
	dict[4] = p4;
	dict[5] = p5;
	dict[6] = p6;
	dict[7] = p7;
	dict[8] = p8;
	dict[9] = p9;
	dict[10] = p10;
	dict[11] = p11;
	dict[12] = p12;
	dict[13] = p13;
	dict[14] = p14;
	dict[15] = p15;
	dict[16] = p16;
	dict[17] = p17;
	dict[18] = p18;
	dict[19] = p19;
	dict[20] = p20;
	dict[21] = p30;
	dict[22] = p40;
	dict[23] = p50;
	dict[24] = p60;
	dict[25] = p70;
	dict[26] = p80;
	dict[27] = p90;
	dict[28] = p100;
	dict[29] = p100;
	dict[30] = p1000;
	dict[31] = p10000;*/

	//char* toto =find_max_of("2000", dict, 31)->name;
	dprintf(1,"fdbdf");
	return (0);
}