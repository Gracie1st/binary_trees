#include "binary_trees.h"
/**
 * binary_tree_is_a_leaf - checks if a node is a leaf
 * @node:  pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_a_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	else
		return (0);
}
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree:  pointer to the root node of the tree to count the number of leaves
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t right_c, left_c;

	if (!tree)
		return (0);

	if (tree != NULL && binary_tree_is_a_leaf(tree))
		return (1);

	left_c = binary_tree_leaves(tree->left);
	right_c = binary_tree_leaves(tree->right);
	return (left_c + right_c);
}
