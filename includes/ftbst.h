#ifndef FT_BST_H
# define FT_BST_H

// STRUCTURES
typedef struct s_entry {
	int	key;
	char	*value;
}	t_entry;

typedef struct s_node {
	t_entry	*entry;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

// GLOBAL VARIABLES
// Initialize to NULL
t_node	*g_root;

// FUNCTION DECLARATIONS
t_node	*create_node(t_entry *entry);

t_entry  *create_entry(int key, char *value);

t_node	*insert_entry(t_node *root, int key, char *value);

#endif
