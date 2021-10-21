#include "ex00/btree_create_node.c"
#include "ex01/btree_apply_prefix.c"
#include "ex02/btree_apply_infix.c"
#include "ex03/btree_apply_suffix.c"
#include "ex04/btree_insert_data.c"
#include "ex05/btree_search_item.c"

#include <stdio.h>

int cmp(void *a1, void *a2)
{
	return (*(int*)a1 - *(int*)a2);
}

void	print(void *data)
{
	printf("%d ", *(int*)data);
}

int main()
{
	printf("\n\033[33;1;40m===================== ex00 ====================\033[32;1;40m\n\n");
	void *p;
	int a = 4;
	p = &a;
	t_btree *buba = btree_create_node(p);
	printf("4 -> %d\n", *(int*)(buba->item));
	printf("0x0 -> %p\n", buba->left);
	printf("0x0 -> %p\n", buba->right);
	printf("\n\033[33;1;40m===================== ex04 ====================\033[32;1;40m\n\n");
	buba = 0;
	int a1 = 3;
	int a2 = 2;
	int a3 = 4;
	int a4 = 3;
	p = &a1;
	btree_insert_data(&buba, p, cmp);
	p = &a2;
	btree_insert_data(&buba, p, cmp);
	p = &a3;
	btree_insert_data(&buba, p, cmp);
	p = &a4;
	btree_insert_data(&buba, p, cmp);
	printf("3 -> %d\n2 -> %d\n4 -> %d\n3 -> %d", *(int *)buba->item, *(int *)buba->left->item, *(int *)buba->right->item, *(int *)buba->right->left->item);
	printf("\n\033[33;1;40m===================== ex01 ====================\033[32;1;40m\n\n");
	int arr[] = {5, 4, 2, 7, 1, 3, 4, 6};
	int i = 0;
	free(buba);
	buba = 0;
	while (i < 8)
	{
		btree_insert_data(&buba, (void*)(&(arr[i])), cmp);
		i++;
	}
	printf("5 4 2 1 3 4 7 6 -> ");
	btree_apply_prefix(buba, print);
	printf("\n");
	printf("\n\033[33;1;40m===================== ex02 ====================\033[32;1;40m\n\n");
	printf("1 2 3 4 4 5 6 7 -> ");
	btree_apply_infix(buba, print);
	printf("\n");
	printf("\n\033[33;1;40m===================== ex03 ====================\033[32;1;40m\n\n");
	printf("1 3 2 4 4 6 7 5 -> ");
	btree_apply_suffix(buba, print);
}
