
# how to test
# copy to root dirrectory of day (where other ex** folders)
# comment all task you don't need
# run in cmd ->
# chmod 777 test.sh
# to start test ->
# ./test.sh

# ex00

# test .c files
echo "\033[33;1;40m=================== ex00 ==================="
gcc -Wall -Wextra -Werror -o ex00/e1.out ex00/*.c
echo "123" >> ex00/t1.txt
echo '\033[32;1;40m123 ->'
./ex00/e1.out ex00/t1.txt
echo "qweqwe" >> ex00/t2
echo "\033[32;1;40mqweqwe ->"
./ex00/e1.out ex00/t2
echo "\033[32;1;40mFile name missing. ->"
ex00/e1.out
echo "\033[32;1;40mToo many arguments. ->"
ex00/e1.out 1 2 3
echo "\033[32;1;40mCannot read file."
ex00/e1.out 2.ryr
echo "\033[0m"
rm -rf ex00/t1.txt ex00/t2 ex00/e1.out

# test makefile
echo "\033[33;1;40m---------- make00 ----------\033[0m"
cd ex00
make -f Makefile
make -f Makefile clean
echo "123qwe" >> t.qwe
echo "\033[32;1;40m123qwe ->"
./ft_display_file t.qwe
echo "\033[0m"
rm -rf t.qwe
make -f Makefile fclean
cd ..

# ex01

#test .c files
echo "\033[33;1;40m=================== ex01 ==================="
cd ex01
gcc -Wall -Wextra -Werror *.c
echo "123" >> t1.txt
echo "\033[32;1;40m123 ->"
./a.out t1.txt
echo "\033[32;1;40mft_cat: ../EFKAkajefkA8: No such file or directory"
./a.out ../EFKAkajefkA8
echo "\033[32;1;40m123\nqwe ->"
echo "qwe" >> t2
./a.out t1.txt t2
echo "\033[32;1;40m(print stdin, press ctrl+d to continue checking) ->\033[0m"
./a.out
rm -rf t1.txt t2 a.out
cd ..

# test makefile
echo "\033[33;1;40m---------- make01 ----------\033[0m"
cd ex01
make -f Makefile
make -f Makefile clean
echo "123" >> 1
echo "qwe" >> 2
echo "\033[32;1;40m123\nqwe ->"
./ft_cat 1 2
echo "\033[32;1;40mft_cat: ./rgrg444ge: No such file or directory ->"
./ft_cat ./rgrg444ge
echo "\033[0m"
rm -rf 1 2
make -f Makefile fclean
cd ..

# ex02

# test .c files
echo "\033[33;1;40m=================== ex02 ==================="
cd ex02
gcc -Wall -Wextra -Werror *.c
echo "123" >> 1
echo "\033[32;1;40m23 ->"
./a.out -c 3 1
echo "qwe" >> 2
echo "\033[32;1;40mqwe ->"
./a.out -c 1000 2
echo "\033[32;1;40m(no newline) ->"
./a.out -c 0 1
touch 3
echo "\033[32;1;40m(no newline) ->"
./a.out -c 10 3
echo "\033[32;1;40m==> 1 <==\n23\n\n==> 2 <==\nwe\nft_tail: ggg: No such file or directory ->"
./a.out -c 3 1 2 ggg
echo "\033[0m"
rm -rf a.out 1 2 3
cd ..

echo "\033[33;1;40m---------- make02 ----------\033[0m"
cd ex02
make -f Makefile
make -f Makefile clean
echo "123" >> 1
echo "\033[32;1;40m23 ->"
./ft_tail -c 3 1
echo "\033[0m"
rm -rf 1
make -f Makefile fclean
cd ..














