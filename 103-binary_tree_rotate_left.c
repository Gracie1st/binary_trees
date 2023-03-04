#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *parent = NULL;
	binary_tree_t *aux = NULL;

	if (tree == NULL)
		return (NULL);

	parent = tree->parent;
	aux = tree->right;

	tree->right = aux->left;
	if (aux->left != NULL)
		aux->left->parent = tree;

	aux->left = tree;
	tree->parent = aux;
	aux->parent = parent;

	if (parent != NULL)
	{
		if (parent->right == tree)
			parent->right = aux;
		else
			parent->left = aux;
	}

	return (aux);
}
