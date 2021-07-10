#ifndef FT_BST_H
# define FT_BST_H

typedef struct	s_entry {
	int	key;
	char	*value;
}	t_entry;

typedef struct	s_node {
	t_entry	*entry;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

char	*get_entry_value(int key);

#endif
