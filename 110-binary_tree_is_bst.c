#include "binary_trees.h"

int bst_check_recursion(const binary_tree_t *tree, int flag, int min, int max);
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bst_check_recursion(tree, 1, -2147483648, 2147483647));
}

/**
 * bst_check_recursion - aux function for check bst
 * @tree: pointer to the root node of the tree to check
 * @flag: return
 * @min: min possible number for a place in the tree
 * @max: max possible number for a place in the tree
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int bst_check_recursion(const binary_tree_t *tree, int flag, int min, int max)
{
	if (tree->left != NULL)
	{
		if (tree->left->n < tree->n && tree->left->n > min)
			flag = bst_check_recursion(tree->left, flag, min, tree->n);
		else
			return (0);
	}

	if (tree->right != NULL)
	{
		if (tree->right->n > tree->n && tree->right->n < max)
			flag = bst_check_recursion(tree->right, flag, tree->n, max);
		else
			return (0);
	}

	return (flag);
}
