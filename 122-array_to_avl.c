#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 * If a value of the array is already present in the tree,
 * this value must be ignored
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	bst_t *tree = NULL;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		avl_insert(&tree, array[i]);
	}

	return (tree);
}
