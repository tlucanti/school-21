
// #include "ex00/btree_create_node.c"
// #include "ex01/btree_apply_prefix.c"
// #include "ex02/btree_apply_infix.c"
// #include "ex03/btree_apply_suffix.c"
// #include "ex05/btree_search_item.c"
// #include "ex06/btree_level_count.c"
#include "ex07/btree_apply_by_level.c"

#include <stdio.h>
#include "ex04/btree_insert_data.c"
#include <stdlib.h>
#include <string.h>

int	cmp(void *s1, void *s2)
{
	s1 = (char *)s1;
	s2 = (char *)s2;
	while (*(char *)s1 && *(char *)s2)
	{
		if (*(char *)s1 != *(char *)s2)
			break ;
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}

void pr(void *a)
{
	printf("%s\n", (char *)a);
}

int main() {

 // ex00 
	printf("\n==================== ex00 ====================\n");

	t_btree *t0 = 0;
	int i0 = 123;
	t0 = btree_create_node(&i0);
	printf("123 -> %d", *(int *)t0->item);

 // ex01 
	printf("\n==================== ex01 ====================\n");

	t_btree	*t1 = 0;
	int i = 0;
	char * data = "0001\0000010\0000011\0000100\0000101\0000110\0000111\0001010";
	btree_insert_data(&t1, data, cmp);
	btree_insert_data(&t1, data + 5, cmp);
	btree_insert_data(&t1, data + 25, cmp);
	btree_insert_data(&t1, data + 15, cmp);
	btree_insert_data(&t1, data + 30, cmp);
	btree_insert_data(&t1, data + 20, cmp);
	btree_insert_data(&t1, data + 35, cmp);
	btree_insert_data(&t1, data + 10, cmp);
	printf("0001\n0010\n0110\n0100\n0011\n0101\n0111\n1010\n->\n");
	btree_apply_prefix(t1, pr);
	// printf("\n==================== ex02 ====================\n");
	// printf("0001\n0010\n0011\n0100\n0101\n0110\n0111\n1010\n");
	// btree_apply_infix(t1, pr);
	// printf("\n==================== ex03 ====================\n");
	// printf("0011\n0101\n0100\n1010\n0111\n0110\n0010\n0001\n");
	// btree_apply_suffix(t1, pr);
	// printf("\n==================== ex05 ====================\n");
	// printf("1010 -> %s\n", (char *)(btree_search_item(t1, data + 35, cmp)));
	// printf("\n==================== ex06 ====================\n");
	// i = btree_level_count(t1);
	// printf("4 -> %d\n", i);
	printf("\n==================== ex07 ====================\n");
	// btree_apply_by_level(t1, pr);
}