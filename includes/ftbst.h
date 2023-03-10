#ifndef FTBST_H
# define FTBST_H

// STRUCTURES
typedef struct s_entry {
	unsigned int	key;
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

t_entry	*create_entry(unsigned int key, char *value);

t_node	*insert_entry(t_node *root, unsigned int key, char *value);

char	*get_entry_value(t_node *root, unsigned int key);

#endif
