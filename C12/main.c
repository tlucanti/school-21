
#include "ex00/ft_create_elem.c"
#include "ex01/ft_list_push_front.c"
#include "ex02/ft_list_size.c"
#include "ex03/ft_list_last.c"
#include "ex04/ft_list_push_back.c"
#include "ex05/ft_list_push_strs.c"
#include "ex06/ft_list_clear.c"
#include "ex07/ft_list_at.c"
#include "ex08/ft_list_reverse.c"
#include "ex09/ft_list_foreach.c"
#include "ex10/ft_list_foreach_if.c"
#include "ex11/ft_list_find.c"
#include "ex12/ft_list_remove_if.c"
#include "ex13/ft_list_merge.c"
#include "ex14/ft_list_sort.c"
#include "ex15/ft_list_reverse_fun.c"
#include "ex16/ft_sorted_list_insert.c"
#include "ex17/ft_sorted_list_merge.c"

#include <stdio.h>
#include <string.h>

void f6(void *d) {
	printf("cleared: %s\n", (char *)d);
}

void clr(void *d) {
	(void)(d);
}

void f9(void *d) {
	printf("touched: %s\n", (char *)d);
}

int f10(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
}

int f12(void *a, void *b)
{
	return (*(int *)a % 2 + *(int *)b % 2);
}

int g12(void *a, void *b)
{
	return (1 - *(int *)a % 2 + *(int *)b % 2);
}

void f12_(void *d) {
	printf("cleared: %d\n", *(int *)d);
}

void pr(void *a)
{
	printf("%d ", *(int *)a);
}

int f14(void *a, void *b)
{
	return (*(int *)b - *(int *)a);
}



int main()
{

	// ex00 (ft_create_elem)

	printf("\n\033[33;1;40m===================== ex00 ====================\033[32;1;40m\n\n");
	
	t_list *l0 = 0;
	void *ptr0;
	int i0 = 123;
	ptr0 = &i0;
	l0 = ft_create_elem(ptr0);
	printf("123 -> %d\n", *(int *)(l0->data));

	// ex01 (ft_list_push_front)

	printf("\n\033[33;1;40m===================== ex01 ====================\033[32;1;40m\n\n");
	t_list *l1 = 0;
	t_list *r1 = 0;
	int i1 = 123;
	void *ptr11 = &i1;
	char c1[] = "qwe";
	void *ptr12 = &c1;

	ft_list_push_front(&r1, ptr11); // push to empty
	printf("123 -> %d\n", *(int *)r1->data);

	l1 = ft_create_elem(ptr11);
	r1 = l1;
	printf("%p: 123 -> %d\n", r1, *(int *)(r1->data));
	ft_list_push_front(&l1, ptr12);
	printf("%p: qwe -> %s\n", l1, (char *)(l1->data));
	printf("%p -> %p\n", r1, l1->next);

	// ex02 (ft_list_size)

	printf("\n\033[33;1;40m===================== ex02 ====================\033[32;1;40m\n\n");
	t_list *l2 = 0;
	int i2 = 123;
	l2 = ft_create_elem(&i2);
	printf("1 -> %d\n", ft_list_size(l2)); // size of empty
	for (int i = 0; i < 5; i++)
		ft_list_push_front(&l2, &i2);
	printf("6 -> %d\n", ft_list_size(l2));

	// ex03 (ft_list_last)

	printf("\n\033[33;1;40m===================== ex03 ====================\033[32;1;40m\n\n");

	t_list *l3 = 0;
	t_list *r3 = 0;

	char i3[] = "lel";
	char j3[] = "qwe";
	printf("0x0 -> %p\n", ft_list_last(l3));
	ft_list_push_front(&r3, &i3); // last of one
	printf("lel -> %s\n", (char *)r3->data);
	l3 = ft_create_elem(&j3);
	printf("qwe -> %s\n", l3->data); // last of one
	for (int i = 0; i < 5; i++) // last of many
		ft_list_push_front(&l3, &i3);
	printf("qwe -> %s\n", (char *)ft_list_last(l3)->data);

	// ex04 (ft_list_push_back)

	printf("\n\033[33;1;40m===================== ex04 ====================\033[32;1;40m\n\n");

	t_list *l4 = 0;
	char i4[] = "lol";
	char j4[] = "qwe";
	ft_list_push_back(&l4, &i4); // push empty
	printf("lol -> %s\n", (char *)l4->data);
	ft_list_push_back(&l4, &j4); // push one
	printf("qwe -> %s\n", (char *)l4->next->data);

	// ex05 (ft_list_push_strs)

	printf("\n\033[33;1;40m===================== ex05 ====================\033[32;1;40m\n\n");

	t_list *l5;
	char **s5 = (char **) malloc (sizeof(char *) * 3);
	char c51[] = "1";
	char c52[] = "2";
	char c53[] = "3";
	s5[0] = c51;
	s5[1] = c52;
	s5[2] = c53;

	printf("0x0 -> %p\n", ft_list_push_strs(0, 0)); // push of empty
	l5 = ft_list_push_strs(3, s5);
	for (int i = 0; i++ < 3; l5 = l5->next)
		printf("%d -> %s\n", 4 - i, (char *)(l5->data));
	free(s5);

	// ex06 (ft_list_clear)

	printf("\n\033[33;1;40m===================== ex06 ====================\033[32;1;40m\n\n");

	t_list *l6;
	t_list *r6;
	char **s6 = (char **) malloc (sizeof(char *) * 3);
	char c61[] = "qwe";
	char c62[] = "asd";
	char c63[] = "zxc";
	s6[0] = c61;
	s6[1] = c62;
	s6[2] = c63;
	l6 = ft_list_push_strs(3, s6);
	r6 = l6->next;
	ft_list_clear(l6, f6);
	printf("%p != %p\n", r6, l6->next);
	free(s6);

	// ex07 (ft_list_at)

	printf("\n\033[33;1;40m===================== ex07 ====================\033[32;1;40m\n\n");

	t_list *l7 = 0;
	int i7 = 123;
	int j7 = 456;
	ft_list_push_back(&l7, &j7);
	printf("456 -> %d\n", *(int *)ft_list_at(l7->data, 0));
	for (int i=0; i<10; i++)
		ft_list_push_back(&l7, &i7);
	ft_list_push_back(&l7, &j7);
	for (int i=0; i<5; i++)
		ft_list_push_back(&l7, &i7);
	ft_list_push_back(&l7, &j7);
	printf("456 -> %d\n", *(int *)ft_list_at(l7, 11)->data);
	printf("456 -> %d\n", *(int *)ft_list_at(l7, 17)->data);
	printf("0x0 -> %p\n", ft_list_at(l7, 18));
	ft_list_clear(l7, clr);

	// ex08 (ft_list_reverse)

	printf("\n\033[33;1;40m===================== ex08 ====================\033[32;1;40m\n\n");

	t_list *l8 = 0;
	int a8[] = {1, 2, 3, 4, 5};
	for (int i=0; i<0; i++)
		ft_list_push_back(&l8, a8 + i);
	for (int i=0; i<0; i++)
		printf("%d ", *(int *)ft_list_at(l8, i)->data);
	ft_list_reverse(&l8);
	printf("\n");
	for (int i=0; i<1; i++)
		printf("%p ", ft_list_at(l8, i));
	ft_list_clear(l8, clr);

	// ex09 (ft_list_foreach)

	printf("\n\033[33;1;40m===================== ex09 ====================\033[32;1;40m\n\n");

	t_list *l9;
	char **s9 = (char **) malloc (sizeof(char *) * 3);
	char c91[] = "3";
	char c92[] = "2";
	char c93[] = "1";
	s9[0] = c91;
	s9[1] = c92;
	s9[2] = c93;
	l9 = ft_list_push_strs(3, s9);
	printf("1 -> 2 -> 3:\n");
	ft_list_foreach(l9, f9);
	ft_list_clear(l9, clr);
	free(s9);

	// ex10 (ft_list_foreach_if)

	printf("\n\033[33;1;40m===================== ex10 ====================\033[32;1;40m\n\n");

	t_list *l10;
	char **s10 = (char **) malloc (sizeof(char *) * 3);
	char c101[] = "1";
	char c102[] = "2";
	char c103[] = "1";
	s10[0] = c101;
	s10[1] = c102;
	s10[2] = c103;
	l10 = ft_list_push_strs(3, s10);
	printf("1 -> 1:\n");
	ft_list_foreach_if(l10, f9, c103, f10);
	ft_list_clear(l10, clr);
	free(s10);

	// ex11 (ft_list_find)

	printf("\n\033[33;1;40m===================== ex11 ====================\033[32;1;40m\n\n");

	t_list *l11;
	t_list *r11;
	char **s11 = (char **) malloc (sizeof(char *) * 3);
	char c111[] = "1";
	char c112[] = "2";
	char c113[] = "1";
	char c114[] = "4";
	s11[0] = c111;
	s11[1] = c112;
	s11[2] = c113;
	l11 = ft_list_push_strs(3, s11);
	r11 = ft_list_find(l11, "1", f10);
	printf("%p == %p\n", l11->next, r11);

	c113[0] = '3';
	r11 = ft_list_find(l11, "1", f10);
	printf("%p == %p\n", l11->next->next, r11);
	r11 = ft_list_find(l11, c114, f10);
	printf("0x0 -> %p\n", r11);
	ft_list_clear(l11, clr);
	ft_list_clear(r11, clr);

	// ex12 (ft_list_remove_if)

	printf("\n\033[33;1;40m===================== ex12 ====================\033[32;1;40m\n\n");

	t_list *l12 = 0;
	t_list *r12 = 0;
	int i12 = 0;
	int a12[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b12[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (int i=0; i < 10; i++)
		ft_list_push_back(&l12, &a12[i]);
	ft_list_remove_if(&l12, &i12, f12, f12_);
	printf("\n1 3 5 7 9 -> ");
	ft_list_foreach(l12, pr);
	printf("\n");
	for (int i=0; i < 10; i++)
		ft_list_push_back(&r12, &b12[i]);
	ft_list_remove_if(&r12, &i12, g12, f12_);
	printf("2 4 6 8 10 -> ");
	ft_list_foreach(r12, pr);
	ft_list_clear(l12, clr);
	ft_list_clear(r12, clr);

	// ex13 (ft_list_merge)
	
	printf("\n\033[33;1;40m===================== ex13 ====================\033[32;1;40m\n\n");

	t_list *l13 = 0;
	t_list *r13 = 0;
	int a13[] = {1, 2, 3, 4, 5};
	int b13[] = {6, 7, 8, 9, 10};
	for (int i=0; i < 5; i++)
		ft_list_push_back(&r13, &a13[i]);

	ft_list_merge(&l13, r13);
	printf("1 2 3 4 5 -> ");
	ft_list_foreach(l13, pr);

	r13 = 0;
	ft_list_merge(&l13, r13);
	printf("\n1 2 3 4 5 -> ");
	ft_list_foreach(l13, pr);

	r13 = 0;
	for (int i=0; i < 5; i++)
		ft_list_push_back(&r13, &b13[i]);
	ft_list_merge(&l13, r13);
	printf("\n1 2 3 4 5 6 7 8 9 10 -> ");
	ft_list_foreach(l13, pr);
	ft_list_clear(l13, clr);

	// ex14 (ft_list_sort)

	printf("\n\033[33;1;40m===================== ex14 ====================\033[32;1;40m\n\n");

	t_list *l14 = 0;
	int a14[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	for (int i=0; i < 10; i++)
		ft_list_push_back(&l14, &a14[i]);

	ft_list_sort(&l14, f14);
	ft_list_foreach(l14, pr);

	// ex15 (ft_list_reverse_fun)

	printf("\n\033[33;1;40m===================== ex15 ====================\033[32;1;40m\n\n");

	t_list *l15 = 0;
	int a15[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	for (int i=0; i < 10; i++)
		ft_list_push_back(&l15, &a15[i]);

	printf("1 .. 10 -> ");
	ft_list_reverse_fun(l15);
	ft_list_foreach(l15, pr);
	l15 = l15->next;
	printf("\n10 .. 2 -> ");
	ft_list_reverse_fun(l15);
	ft_list_foreach(l15, pr);

	// ex16 (ft_sorted_list_insert)

	printf("\n\033[33;1;40m===================== ex16 ====================\033[32;1;40m\n\n");

	t_list *l16 = 0;
	int a16[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (int i=0; i < 10; i++)
		ft_list_push_back(&l16, &a16[i]);
	int a26 = 6;
	int a36 = -5;
	int a46 = 16;
	ft_sorted_list_insert(&l16, &a26, f14);
	ft_list_foreach(l16, pr);
	printf("\n");
	ft_sorted_list_insert(&l16, &a36, f14);
	ft_list_foreach(l16, pr);
	printf("\n");
	ft_sorted_list_insert(&l16, &a46, f14);
	ft_list_foreach(l16, pr);

	// ex17

	printf("\n\033[33;1;40m===================== ex17 ====================\033[32;1;40m\n\n");

	t_list *l17 = 0;
	t_list *r17 = 0;
	int a17[] = {1, 2, 3, 4, 5};
	for (int i=0; i < 5; i++)
		ft_list_push_back(&l17, &a17[i]);
	ft_list_foreach(l17, pr);
	int b17[] = {1, 2, 3, 4, 5};
	for (int i=0; i < 5; i++)
		ft_list_push_back(&r17, &b17[i]);
	ft_sorted_list_merge(&l17, r17, f14);
	ft_list_foreach(l17, pr);
}



































