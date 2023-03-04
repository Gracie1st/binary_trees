#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 * if tree is NULL, the created node must become the root node.
 * If the value is already present in the tree is ignored
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *aux = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	aux = *tree;
	while (1)
	{
		if (aux->n == value)
			return (NULL);
		if (value > aux->n)
		{
			if (aux->right != NULL)
				aux = aux->right;
			else
			{
				aux->right = binary_tree_node(aux, value);
				return (aux->right);
			}
		}
		else
		{
			if (aux->left != NULL)
				aux = aux->left;
			else
			{
				aux->left = binary_tree_node(aux, value);
				return (aux->left);
			}
		}
	}
}
