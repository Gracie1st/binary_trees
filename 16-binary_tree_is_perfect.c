#include "binary_trees.h"
/**
 * left_depth - left depht of the binary tree
 * @tree: pointer to the root node of the tree to check
 * Return: depth of the binary tree
 */
int left_depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree != NULL)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}
/**
 * perfection - checks if the binary tree is perfect or not
 * @tree: pointer to the root node of the tree to check
 * @depth: depth of the binary tree
 * @level: level of the binary tree
 * Return: 1 if binary tree is perfect, otherwise 0
 *
 */
int perfection(const binary_tree_t *tree, int depth, int level)
{
	if (!tree)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
	{
		if (depth == level + 1)
			return (1);
		else
			return (0);
	}
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (perfection(tree->left, depth, level + 1) &&
		perfection(tree->right, depth, level + 1));
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if binary tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth, level;

	level = 0;
	if (!tree)
		return (0);
	depth = left_depth(tree);
	return (perfection(tree, depth, level));
}
