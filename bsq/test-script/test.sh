# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vanouri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/26 14:39:04 by vanouri           #+#    #+#              #
#    Updated: 2021/07/27 10:03:56 by vanouri          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

clear
echo "\t\t===== test 0 ====="
touch map.txt
perl scripts/map_gen.pl 1 1 2 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "o"
rm map.txt

echo "\n\t\t===== test 1 ====="
touch map.txt
perl scripts/map_gen.pl 0 0 10 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "map error"
rm map.txt

echo "\n\t\t===== test 2 ====="
touch map.txt
perl scripts/map_gen.pl 0 1 10 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "map error"
rm map.txt

echo "\n\t\t===== test 3 ====="
touch map.txt
perl scripts/map_gen.pl 1 0 10 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "map error"
rm map.txt

echo "\n\t\t===== test 4 ====="
touch map.txt
perl scripts/map_gen.pl 1 1 0 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "x"
rm map.txt

echo "\n\t\t===== test 5 ====="
touch map.txt
perl scripts/map_gen.pl 1 0 10 > map.txt
echo "\nton resultat :\n"
./BSQ .
echo "\nresultat attendu :\n"
echo "map error"
rm map.txt

echo "\n\t\t===== test 6 ====="
touch map.txt
perl scripts/map_gen.pl -1 -1 -1 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "map error"
rm map.txt

echo "\n\t\t===== test 7 ====="
touch map.txt
perl scripts/map_gen.pl 5 5 3 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "ce test attend une map valide"
rm map.txt

echo "\n\t\t===== test 8 ====="
touch map.txt
perl scripts/map_gen.pl 10 10 20 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "ce test attend une map sans aucun carré"
rm map.txt

echo "\n\t\t===== test 9 ====="
touch map.txt
perl scripts/map_gen.pl 10 10 00 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "ce test attend une map pleine"
rm map.txt

echo "\n\t\t===== test 10 ====="
touch map.txt
perl scripts/map_gen.pl 10 10 1 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "ce test attend une map valide"
rm map.txt

echo "\n\t\t===== test 11 ====="
touch map.txt
perl scripts/map_gen.pl 10 10 19 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "ce test attend une map valide"
rm map.txt

echo "\n\t\t===== test 12 ====="
touch map.txt
perl scripts/map_gen.pl 10 -1 0 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "map error"
rm map.txt

echo "\n\t\t===== test 13 ====="
touch map.txt
perl scripts/map_gen.pl 10 -1 0 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "map error"
rm map.txt

echo "\n\t\t===== test 14 ====="
touch map.txt
perl scripts/map_gen.pl 1 10 0 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "ce test attend une map valide"
rm map.txt

echo "\n\t\t===== test 15 ====="
touch map.txt
perl scripts/map_gen.pl 10 1 0 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "ce test attend une map valide"
rm map.txt

echo "\n\t\t===== test 16 ====="
touch map.txt
touch map2.txt
touch map3.txt
perl scripts/map_gen.pl 10 10 3 > map.txt
perl scripts/map_gen.pl 0 0 3 > map2.txt
perl scripts/map_gen.pl 10 10 5 > map3.txt
echo "\nton resultat :\n"
./BSQ map.txt map2.txt map3.txt
echo "\nresultat attendu :\n"
echo "le premier est valide"
echo "le deuxieme produit un map error"
echo "le troisieme est valide"
echo "chaques resulats a comme separateur un /n"
rm map.txt
rm map2.txt
rm map3.txt

echo "\n\t\t===== test 17 ====="
touch map.txt
perl scripts/map_gen.pl 10 10 3 > map.txt
echo "\nton resultat :\n"
cat map.txt| ./BSQ
echo "\nce test, test l'entrée standard"
echo "resultat attendu :\n"
echo "ce test attend une map valide"
rm map.txt

echo "\n\t\t===== test 18 ====="
touch map.txt
perl scripts/map_gen.pl 0 0 3 > map.txt
echo "\nton resultat :\n"
cat map.txt| ./BSQ
echo "\nce test, test l'entrée standard"
echo "resultat attendu :\n"
echo "map error"
rm map.txt

echo "\n\t\t===== test 19 ====="
touch map.txt
perl scripts/map_gen.pl 10 10 20 > map.txt
echo "\nton resultat :\n"
cat map.txt| ./BSQ
echo "\nce test, test l'entrée standard"
echo "resultat attendu :\n"
echo "ce test attend une map sans carré"
rm map.txt

echo "\n\t\t===== test 20 ====="
touch map.txt
perl scripts/map_gen.pl 50 50 30 > map.txt
echo "\nton resultat :\n"
cat map.txt| ./BSQ
echo "\nce test, test l'entrée standard"
echo "resultat attendu :\n"
echo "ce test attend une map valide"
rm map.txt
