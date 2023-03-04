#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: pointer to the node containing a value equals to value
 * If tree is NULL or if nothing is found, return NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	while (1)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->right != NULL && value > tree->n)
			tree = tree->right;
		else if (tree->left != NULL && value < tree->n)
			tree = tree->left;
		else
			return (NULL);
	}
}
