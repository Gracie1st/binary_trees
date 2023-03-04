#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: how many nodes are above tree
 *
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	depth = 0;
	if (!tree)
		return (depth);

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
