_END=$'\x1b[0m'
_BOLD=$'\x1b[1m'
_UNDER=$'\x1b[4m'
_REV=$'\x1b[7m'

_GREY=$'\x1b[30m'
_RED=$'\x1b[31m'
_GREEN=$'\x1b[32m'
_YELLOW=$'\x1b[33m'
_BLUE=$'\x1b[34m'
_PURPLE=$'\x1b[35m'
_CYAN=$'\x1b[36m'
_WHITE=$'\x1b[37m'

_OK="${_GREEN}OK ✅${_END}"
_KO="${_RED}KO ❌${_END}"
_ISOK=1


clear
echo "${_BOLD}${_RED}//START TEST SCRIPT BSQ${_END}"

echo "\n${_BOLD}${_BLUE}//--------- check norm${_END}"
norminette */*.[ch] | grep -E '^(Error|Warning)'
echo "${_BOLD}${_BLUE}//--------- end${_END}"

echo "\n\n${_BOLD}${_CYAN}//-------------- makefile test${_END}"

make clean && make && make fclean && make && make clean && ls -la bsq

# printf "\n${_BOLD}${_WHITE}//-------------------- no file : ${_END}"
# rm -rf tmp_map
# ./bsq tmp_map > stdout 2> stderr
# echo "map error" > check
# if [[ $(< stderr) = $(< check) ]]
# then
# 	echo ${_OK}
# else
# 	echo ${_KO}
	_ISOK=0
# fi
# rm -rf tmp tmp_map check stdout stderr

echo "\n${_BOLD}${_BLUE}//--------- full clean${_END}"
make fclean > tmp
echo "${_BOLD}${_BLUE}//--------- building${_END}"
make > tmp
echo "${_BOLD}${_BLUE}//--------- clean tmp files${_END}"
make clean > tmp

echo "\n\n${_BOLD}${_CYAN}//-------------- file error test${_END}"
echo "${_BOLD}${_GREY}//all tests should print 'map error' on stderr${_END}"

printf "\n${_BOLD}${_WHITE}//-------------------- no file : ${_END}"
rm -rf tmp_map
./bsq tmp_map > stdout 2> stderr
echo "map error" > check
if [[ $(< stderr) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr


printf "${_BOLD}${_WHITE}//----------------- empty file : ${_END}"
touch tmp_map
./bsq tmp_map > /dev/null 2> stderr
echo "map error" > check
if [[ $(< stderr) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//--------------------- folder : ${_END}"
mkdir tmp_map
./bsq tmp_map > /dev/null 2> stderr
echo "map error" > check
if [[ $(< stderr) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr


echo "\n\n${_BOLD}${_CYAN}//-------------- map error test${_END}"
echo "${_BOLD}${_GREY}//all tests should print 'map error' on stderr${_END}"


printf "\n${_BOLD}${_WHITE}//------------------ 1 * 0 map : ${_END}"
perl gen.pl 1 0 1 > tmp_map
./bsq tmp_map > stdout 2> stderr
echo "map error" > check
if [[ $(< stderr) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//---------------------- 0 * 1 : ${_END}"
perl gen.pl 0 1 1 > tmp_map
./bsq tmp_map > stdout 2> stderr
echo "map error" > check
if [[ $(< stderr) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//---------------------- 0 * 0 : ${_END}"
perl gen.pl 0 0 1 > tmp_map
./bsq tmp_map > /dev/null 2> stderr
echo "map error" > check
if [[ $(< stderr) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//------------ missing newline : ${_END}"
printf "5.ox\n.....\n....o\n.....\n.....\n....." > tmp_map
./bsq tmp_map > /dev/null 2> stderr
echo "map error" > check
if [[ $(< stderr) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//-------------------- wrong y : ${_END}"
echo "4.ox\n.....\n....o\n.....\n.....\n....." > tmp_map
./bsq tmp_map > /dev/null 2> stderr
echo "map error" > check
if [[ $(< stderr) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//-------------- non uniform x : ${_END}"
echo "5.ox\n.....\n....o\n.....\n....\n....." > tmp_map
./bsq tmp_map > /dev/null 2> stderr
echo "map error" > check
if [[ $(< stderr) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//----------------- wrong char : ${_END}"
echo "5.ox\n.....\n....o\n.....\n...p.\n....." > tmp_map
./bsq tmp_map > /dev/null 2> stderr
echo "map error" > check
if [[ $(< stderr) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//----------- already a square : ${_END}"
echo "xxxx.\nxxxxo\nxxxx.\nxxxx.\n....." > tmp_map
./bsq tmp_map > /dev/null 2> stderr
echo "map error" > check
if [[ $(< stderr) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//---------- duplicate symbols : ${_END}"
echo "5.oo\n.....\n....o\n.....\n.....\n....." > tmp_map
./bsq tmp_map > /dev/null 2> stderr
echo "map error" > check
if [[ $(< stderr) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//------- non pritable symbols : ${_END}"
echo "5.o\xvf\n.....\n....o\n.....\n.....\n....." > tmp_map
./bsq tmp_map > /dev/null 2> stderr
echo "map error" > check
if [[ $(< stderr) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

echo "\n\n${_BOLD}${_CYAN}//-------------- valid map test${_END}"

printf "\n${_BOLD}${_WHITE}//----------------- 1 * 1 full : ${_END}"
echo "1.ox\no" > tmp_map
./bsq tmp_map > stdout 2> stderr
echo "o" > check
if [[ $(< stdout) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//---------------- 1 * 1 empty : ${_END}"
echo "1.ox\n." > tmp_map
./bsq tmp_map > stdout 2> stderr
echo "x" > check
if [[ $(< stdout) == $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//----------------- 2 * 2 full : ${_END}"
echo "2.ox\noo\noo" > tmp_map
./bsq tmp_map > stdout 2> stderr
echo "oo\noo" > check
if [[ $(< stdout) == $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//---------------- 2 * 2 empty : ${_END}"
echo "2.ox\n..\n.." > tmp_map
./bsq tmp_map > stdout 2> stderr
echo "xx\nxx" > check
if [[ $(< stdout) == $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//------------------- top left : ${_END}"
echo "2.ox\n.o\no." > tmp_map
./bsq tmp_map > stdout 2> stderr
echo "xo\no." > check
if [[ $(< stdout) == $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//--------- 5 * 5 standard map : ${_END}"
echo "5.ox\n.....\n....o\n.....\n.....\n....." > tmp_map
./bsq tmp_map > stdout 2> stderr
echo "xxxx.\nxxxxo\nxxxx.\nxxxx.\n....." > check
if [[ $(< stdout) == $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//------- 10 * 10 standard map : ${_END}"
echo "10.ox\no.........\n..........\n..........\n....o.....\n...o......\n..........\n..........\n.......o..\n...o......\no........." > tmp_map
./bsq tmp_map > stdout 2> stderr
echo "o....xxxxx\n.....xxxxx\n.....xxxxx\n....oxxxxx\n...o.xxxxx\n..........\n..........\n.......o..\n...o......\no........." > check
if [[ $(< stdout) == $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr



echo "\n\n${_BOLD}${_CYAN}//-------------- divers test${_END}"

echo "\n${_BOLD}${_BLUE}//-------------- stdin${_END}"
printf "${_BOLD}${_WHITE}//--------------- should solve : ${_END}"
echo "1.ox\no" | ./bsq > stdout 2> stderr
echo "o" > check
if [[ $(< stdout) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//----------- should map error : ${_END}"
echo "abcdefgh" | ./bsq > stdout 2> stderr
echo "map error" > check
if [[ $(< stderr) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

printf "${_BOLD}${_WHITE}//----------- should map error : ${_END}"
printf "abcdefgh" | ./bsq > stdout 2> stderr
echo "map error" > check
if [[ $(< stderr) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr


printf "${_BOLD}${_WHITE}//----------- should map error : ${_END}"
printf "" | ./bsq > stdout 2> stderr
echo "map error" > check
if [[ $(< stderr) = $(< check) ]]
then
	echo ${_OK}
else
	echo ${_KO}
	_ISOK=0
fi
rm -rf tmp tmp_map check stdout stderr

echo "\n\n${_BOLD}${_CYAN}//--------------speed test${_END}"

printf "\n${_BOLD}${_GREEN}//--------- 1 * 1 map${_END}"
perl gen.pl 1 1 1 > tmp_map
time ./bsq tmp_map > tmp
rm -rf tmp tmp_map check stdout stderr

printf "\n${_BOLD}${_GREEN}//--------- 10 * 10 map${_END}"
perl gen.pl 10 10 1 > tmp_map
time ./bsq tmp_map > tmp
rm -rf tmp tmp_map check stdout stderr

printf "\n${_BOLD}${_BLUE}//--------- 100 * 100 map${_END}"
perl gen.pl 100 100 1 > tmp_map
time ./bsq tmp_map > tmp
rm -rf tmp tmp_map check stdout stderr

printf "\n${_BOLD}${_YELLOW}//--------- 1000 * 1000 map${_END}"
perl gen.pl 1000 1000 1 > tmp_map
time ./bsq tmp_map > tmp
rm -rf tmp tmp_map check stdout stderr

# printf "\n${_BOLD}${_RED}//--------- 10000 * 10000 map${_END}"
# perl gen.pl 10000 10000 1 > tmp_map
# time ./bsq tmp_map > tmp
# rm -rf tmp tmp_map check stdout stderr

echo "\n\n${_BOLD}${_BLUE}//--------- full clean${_END}"
make fclean > tmp
rm -f tmp tmp_map check stdout stderr

echo "\n${_BOLD}${_RED}//DONE${_END}"
