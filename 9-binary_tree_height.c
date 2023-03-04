#include "binary_trees.h"
/**
 * traversal_po - post order traversal binary tree
 * @root: root of the analyzed tree
 * @left_c: counter to the left
 * @right_c: counter to the right
 * Return: height of the binary tree
 */
size_t traversal_po(const binary_tree_t *root, size_t left_c, size_t right_c)
{
	if (!root)
		return (-1);
	left_c = traversal_po(root->left, left_c, right_c) + 1;
	right_c = traversal_po(root->right, left_c, right_c) + 1;
	if (right_c > left_c)
		return (right_c);
	return (left_c);
}
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_c, right_c, height;

	left_c = right_c = 0;
	if (!tree)
		return (0);
	height = traversal_po(tree, left_c, right_c);
	return (height);
}
