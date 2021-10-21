#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdio>

using namespace::std;

int main() {
#define r 9
#define c 20
	char __d;
	int **a = (int **) malloc (sizeof(int *) * r);
	for (int i = 0; i < 9; i++)
		a[i] = (int *) malloc (sizeof(int) * c);
	ifstream __f;
	__f.open("../out.txt", ios::in);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++	) {
			__f >> __d;
			a[i][j] = __d - 48;
		}
		//f >> d;
	}
	__f.close();
    //print_a(a, r, c);


	t_array_data *d;

	alg(a, r, c);
	print_a(a, r, c);
	d = init_array_data('.', 'x', 'o');
	print_out(a, r, c, d);
	d = find_max(a, r, c, d);
	printf("%d %d %d\n", d->x, d->y, d->size);
	cout << endl;
	print_out(a, r, c, d);
}