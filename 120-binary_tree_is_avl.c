#include "binary_trees.h"

int avl_check_recursion(const binary_tree_t *tree, int flag);
int bst_check_recursion(const binary_tree_t *tree, int flag, int min, int max);

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (bst_check_recursion(tree, 1, -2147483648, 2147483647) == 0)
		return (0);

	return (avl_check_recursion(tree, 1));
}

/**
 * avl_check_recursion - aux function for recursion
 * @tree: pointer to the root node of the tree to check
 * @flag: return
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int avl_check_recursion(const binary_tree_t *tree, int flag)
{
	int balance;

	if (tree->left != NULL)
		flag = avl_check_recursion(tree->left, flag);

	if (tree->right != NULL)
		flag = avl_check_recursion(tree->right, flag);

	balance = binary_tree_balance(tree);
	if (!(-1 <= balance && balance <= 1))
		return (0);

	return (flag);
}

int balance_recursion(const binary_tree_t *tree, int count);

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor
 * If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right_balance = 0;
	int left_balance = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_balance = balance_recursion(tree->left, 1);
	if (tree->right != NULL)
		right_balance = balance_recursion(tree->right, 1);

	return (left_balance - right_balance);
}

/**
 * balance_recursion - aux function for recursion
 * @tree: pointer to tree
 * @count: counter of height
 * Return: height
 */
int balance_recursion(const binary_tree_t *tree, int count)
{
	int count_r = 0;
	int count_l = 0;

	if (tree->left != NULL)
		count_l = balance_recursion(tree->left, count + 1);

	if (tree->right != NULL)
		count_r = balance_recursion(tree->right, count + 1);

	if (tree->left == NULL && tree->right == NULL)
		return (count);

	if (count_r > count_l)
		return (count_r);
	else
		return (count_l);
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
