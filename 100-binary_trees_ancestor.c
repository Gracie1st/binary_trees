#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: lowest common ancestor on success, NULL if there isn't one.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *tmp;

	if (!first || !second)
		return (NULL);

	tmp = (binary_tree_t *)second;
	while (first)
	{
		while (tmp)
		{
			if (first == tmp)
				return (tmp);
			tmp = tmp->parent;
		}
		tmp = (binary_tree_t *)second;
		first = first->parent;
	}
	return (NULL);

}
