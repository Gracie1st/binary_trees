#include "binary_trees.h"

/**
 *binary_tree_node - create a binary tree node
 *@parent: (binary_tree_t) adress of parent node
 *@value: (int) key
 *
 *Return: NULL or pointer to a new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
	{
		return (NULL);
	}
	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
