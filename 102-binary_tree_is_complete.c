#include "binary_trees.h"

size_t height_recursion(const binary_tree_t *tree, size_t count);
int level_check_recursion(const binary_tree_t *tree,
						  int height, int level, int count, int flag);

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if is complete, 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t height, i;
	int check = 1;

	if (tree == NULL)
		return (0);

	height = height_recursion(tree, 0);

	for (i = 1; i < height; i++)
	{
		check = level_check_recursion(tree, height, height - i, 0, 1);
		if (check == 0)
			return (0);
	}

	return (1);
}

/**
 * level_check_recursion - aux function for recursion
 * @tree: pointer to the root node of the tree to traverse
 * @height: height
 * @level: desire level to check
 * @count: counter for current level
 * @flag: 0 if not complete.
 * Return: flag
 */
int level_check_recursion(const binary_tree_t *tree,
						  int height, int level, int count, int flag)
{

	if (tree->left != NULL)
		flag = level_check_recursion(tree->left, height, level, count + 1, flag);

	if (tree->right != NULL)
		flag = level_check_recursion(tree->right, height, level, count + 1, flag);

	if (count == level && flag == 1 && tree->left == NULL)
		flag = 2;
	else if ((count == level && flag == 2 && tree->left != NULL) ||
			 (count == level && height - 1 != level && tree->left == NULL))
		flag = 0;

	if (count == level && flag == 1 && tree->right == NULL)
		flag = 2;
	else if ((count == level && flag == 2 && tree->right != NULL) ||
			 (count == level && height - 1 != level && tree->right == NULL))
		flag = 0;

	return (flag);
}

/**
 * height_recursion - aux function for recursion
 * @tree: pointer to tree
 * @count: counter of height
 * Return: height
 */
size_t height_recursion(const binary_tree_t *tree, size_t count)
{
	size_t count_r = 0;
	size_t count_l = 0;

	if (tree->left != NULL)
		count_l = height_recursion(tree->left, count + 1);

	if (tree->right != NULL)
		count_r = height_recursion(tree->right, count + 1);

	if (tree->left == NULL && tree->right == NULL)
		return (count);

	if (count_r > count_l)
		return (count_r);
	else
		return (count_l);
}
