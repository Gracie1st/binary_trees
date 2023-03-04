#include "binary_trees.h"
/**
 *binary_tree_insert_left - a fuction
 *that insert a node at the left child of another node
 *
 *@parent: pointer to the node that insert a the left child
 *@value: key (int)
 *Return: pointer to the newly created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *new;

if (!parent)
return (NULL);
new = binary_tree_node(parent, value);
if (!new)
return (NULL);
if (parent->left != NULL)
{
new->left = parent->left;
new->left->parent = new;
}
parent->left = new;
return (new);
}
