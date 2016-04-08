echo -n "Enter a regex> "
read regex
echo -n "Enter a file> "
read inp

g++ inp.cpp
./a.out $regex $inp > new66.l
lex new66.l
gcc lex.yy.c
./a.out

