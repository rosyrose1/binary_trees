#include "binary_trees.h"
/**
 * binary_tree_is_root - checks if a node is a root node in a binary tree
 * @node: A pointer to the node to check.
 * Return: 1 if the node is a root else return 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	else if (node->parent == NULL)
		return (1);
	return (0);
}
