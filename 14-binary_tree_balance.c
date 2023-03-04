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
 * binary_tree_balance - check balancer of binary tree
 * @tree:  pointer to the root node of the tree to count the number of leaves
 * Return: balancer
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	return (height(tree->left) - height(tree->right));
}
