#include "ftbst.h"

// Creates a new BST node structure
t_node	*create_node(t_entry *entry)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	node->entry = entry;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

// Creates a new entry structure
t_entry	*create_entry(int key, char *value)
{
	t_entry	*entry;

	entry = (t_entry *) malloc(sizeof(t_entry));
	entry->key = key;
	entry->value = value;
	return (entry);
}

// Inserts a new dict entry into BST
t_node	*insert_entry(t_node *root, int key, char *value)
{
	t_entry	*entry;

	if (root == NULL)
	{
		entry = create_entry(key, value);
		return (create_node(entry));
	}
	if (key < root->entry->key)
		root->left = insert_entry(root->left, key, value);
	else if (key > root->entry->key)
		root->right = insert_entry(root->right, key, value);
	return (root);
}

// Given an entry key, returns the corresponding value
char	*get_entry_value(t_node *root, int key)
{
	if (root == NULL || root->entry == NULL)
		return (NULL);
	if (root->entry->key == key)
		return (root->entry->value);
	if (key < root->entry->key)
		return (get_entry_value(root->left, key));
	return (get_entry_value(root->right, key));
}
