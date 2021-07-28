# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    loop.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vanouri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/26 14:39:35 by vanouri           #+#    #+#              #
#    Updated: 2021/07/27 10:03:38 by vanouri          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

make re
w=100
h=100
d=10
i=0
while [ $i -lt $1 ]
do
	touch map.txt
	clear
	perl scripts/map_gen.pl $w $h $d > map.txt
	time ./BSQ map.txt
	i=`expr $i + 1`
	sleep 1
	rm map.txt
done
