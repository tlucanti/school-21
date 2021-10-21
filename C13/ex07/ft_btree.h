
#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h>

typedef struct		s_btree
{
	struct			s_btree *left;
	struct			s_btree *right;
	void			*item;
}					t_btree;

typedef struct		s_list
{
	struct 			s_btree *root;
	int				level;
	struct 			s_list *next;
}					t_list;

#endif