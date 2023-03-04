#include "binary_trees.h"
/**
 * traversal - post order traversal binary tree
 * @root: root of the analyzed tree
 * @cnt_r: counter to the left
 * @cnt_l: counter to the right
 * Return: size of the binary tree
 */
size_t traversal(const binary_tree_t *root, size_t cnt_r, size_t cnt_l)
{
	if (!root)
		return (-1);
	cnt_l = traversal(root->left, cnt_r, cnt_l) + 1;
	cnt_r = traversal(root->right, cnt_r, cnt_l) + 1;
	return (cnt_l + cnt_r);
}
/**
 * binary_tree_size - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t counter_l, counter_r, total;

	counter_l = 0;
	counter_r = 0;
	total = 0;

	if (!tree)
		return (0);
	total = traversal(tree, counter_r, counter_l);
	return (total + 1);
}
