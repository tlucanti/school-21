
function next() {
    echo "--------------------------------------------";
}

next;
./a.out "";
echo "empty";

next;
./a.out "1";
echo "none";

next;
./a.out "x-x";
echo "any";

next;
./a.out " x + x = x + x ";
echo "any";

next;
./a.out "x-1";
echo "1";

next;
./a.out "x+1=0";
echo "-1";

next;
./a.out "x=1";
echo "1";

next;
./a.out "0=1+x";
echo "-1";

next;
./a.out "2x=1";
echo "1/2";

next;
./a.out "x^2";
echo "0";

next;
./a.out "x^123 - x^123";
echo "any";

next;
./a.out "x^2 - 4";
echo "2, -2";

next;
./a.out "x^2 + 4";
echo "2j - 2j";

next;
./a.out "x^2 + 2x + 4";
echo "-1-1.7j, -1+1.7j"

next;
./a.out "       123      x      ^      2      +      567   x  + 789    ";
echo "-2.3049-1.0498j, x-2.3049+1.0498j";

next;
./a.out "x^2+x+x+x+x+1+1+1+1=0"
echo "-2"

next;
./a.out "5x^2+6x=-1"
echo "-1, -1/5";
