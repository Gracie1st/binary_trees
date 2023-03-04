#include "binary_trees.h"
/**
 * traversal_p - post order traversal binary tree
 * @tree: root of the analyzed tree
 * @left_c: counter to the left
 * @right_c: counter to the right
 * Return: height of the binary tree
 */
int traversal_p(const binary_tree_t *tree, int left_c, int right_c)
{
	if (!tree)
		return (0);
	left_c = traversal_p(tree->left, left_c, right_c) + 1;
	right_c = traversal_p(tree->right, left_c, right_c) + 1;
	if (right_c > left_c)
		return (right_c);
	return (left_c);
}
/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */
size_t height(const binary_tree_t *tree)
{
	int left_c, right_c, height;

	left_c = right_c = 0;
	if (!tree)
		return (0);
	height = traversal_p(tree, left_c, right_c);
	return (height);
}
/**
 * levelorder - traverse a binary tree, level by level
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * @height_t: height of the tree
 * Return: Nothing
 */
void levelorder(const binary_tree_t *tree, void (*func)(int), int height_t)
{
	if (!tree)
		return;
	if (height_t == 1)
		func(tree->n);
	else if (height_t > 1)
	{
		levelorder(tree->left, func, height_t - 1);
		levelorder(tree->right, func, height_t - 1);
	}
}
/**
 * binary_tree_levelorder - Binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height_t, i;

	if (!tree || !func)
		return;

	height_t = height(tree);
	for (i = 0; i <= height_t; i++)
		levelorder(tree, func, i);
}
