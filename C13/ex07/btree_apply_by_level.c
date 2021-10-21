#include "ft_btree.h"

t_list	*push (t_btree *root, t_list *last, int level)
{
	t_list *new;
	new = (t_list *)malloc(sizeof(t_list));
	new->root = root;
	new->level = level;
	new->next = 0;
	if (last)
		last->next = new;
	return (new);
}

void	bfs(void (*applyf)(void *item, int current_level, int is_first_elem),
	t_list *esp, t_list *last, int ff)
{
	t_list *next;

	if (esp->root->left)
		last = push(esp->root->left, last, esp->level + 1);
	if (esp->root->right)
		last = push(esp->root->right, last, esp->level + 1);
	applyf(esp->root, esp->level, ff);
	next = esp->next;
	if (next)
	{
		ff = (esp->level - next->level) ? 1 : 0;
		free(esp);
		bfs(applyf, next, last, ff);
	}
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_list *list;
	if (!root)
		return ;
	list = push(root, 0, 0);
	bfs(applyf, list, list, 1);
}
