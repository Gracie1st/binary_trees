#include "binary_trees.h"
/**
 * binary_tree_insert_right - funtion for inserts a node as the right-child
 * @parent: node to insert children right side
 * @value: valor of node right to insert
 * Return: pointer to new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_node->parent = parent;
		parent->right->parent = new_node;
		new_node->right = parent->right;
		parent->right = new_node;
	}
	else
		parent->right = new_node;

	return (new_node);
}
