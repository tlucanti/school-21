
# HOW TO TEST:
# 1) chmod 777 test.sh
# 2) ./test.sh
# 3) ????
# 4) PROFIT

echo '==================== ex00 ===================='
echo './a.out\n->'
gcc -Wall -Wextra -Werror ./ex00/ft_print_program_name.c && ./a.out sf esg s rgrgrgr
echo '----------\n./a/out\n->'
./a.out
cp ./a.out ./b.out
rm -rf ./a.out
echo '----------\n./b.out\n->'
./b.out srgsgrsgrrgrsgrs ssssss
cp ./b.out ./ex00/12\?\?\?3\t4567\"89.out
rm -rf ./b.out
echo '----------\n./ex00/12???3t4567"89.out\n->'
./ex00/12\?\?\?3\t4567\"89.out 123 qwe qwe qwe
rm -rf ./ex00/12\?\?\?3\t4567\"89.out

echo '==================== ex01 ===================='
echo 'test1\ntest2\ntest3\n->'
gcc -Wall -Wextra -Werror ./ex01/ft_print_params.c
./a.out test3 test2 test1
echo '----------\nnothing\n->'
./a.out
cp ./a.out ./b.out
rm -rf ./a.out
echo '----------\na\na\na\n->'
./b.out a a a
cp ./b.out ./ex01/12\?\?\?3\t4567\"89.out
rm -rf ./b.out
echo '----------\na\nb\nc\n->'
./ex01/12\?\?\?3\t4567\"89.out a b c
cp ./ex01/12\?\?\?3\t4567\"89.out ./a.out
rm -rf ./ex01/12\?\?\?3\t4567\"89.out
echo '----------\ntest test\n->'
./a.out test\ test
rm -rf ./a.out

echo '==================== ex02 ===================='
echo 'test3\ntest2\ntest1\n->'
gcc -Wall -Wextra -Werror ./ex02/ft_rev_params.c && ./a.out test1 test2 test3
echo '----------\nnothing\n->'
./a.out
cp ./a.out ./b.out
rm -rf ./a.out
echo '----------\ne\nw\nq\n->'
./b.out q w e
cp ./b.out ./ex02/12\?\?\?3\t4567\"89.out
rm -rf ./b.out
echo '----------\ntest test\n->'
./ex02/12\?\?\?3\t4567\"89.out test\ test
rm -rf ./ex02/12\?\?\?3\t4567\"89.out

echo '==================== ex03 ===================='
echo 'test1\ntest2\ntest3\n->'
gcc -Wall -Wextra -Werror ./ex03/ft_sort_params.c
./a.out test3 test2 test1
echo '----------\nnothing\n->'
./a.out
cp ./a.out ./b.out
rm -rf ./a.out
echo '----------\na\na\na\n->'
./b.out a a a
cp ./b.out ./ex03/12\?\?\?3\t4567\"89.out
rm -rf ./b.out
echo '----------\na\nb\nc\n->'
./ex03/12\?\?\?3\t4567\"89.out a b c
cp ./ex03/12\?\?\?3\t4567\"89.out ./a.out
rm -rf ./ex03/12\?\?\?3\t4567\"89.out
echo '----------\ntest test\n->'
./a.out test\ test
rm -rf ./a.out

norminette -R CheckForbiddenSourceHeader ./ex00/ft_print_program_name.c | grep -E '^(Error|Warning)'
norminette -R CheckForbiddenSourceHeader ./ex01/ft_print_params.c | grep -E '^(Error|Warning)'
norminette -R CheckForbiddenSourceHeader ./ex02/ft_rev_params.c | grep -E '^(Error|Warning)'
norminette -R CheckForbiddenSourceHeader ./ex03/ft_sort_params.c | grep -E '^(Error|Warning)'
