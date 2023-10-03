#include "binary_trees.h"
/**
 * binary_tree_sibling - Finds the sibling node of a given node ina binary tree
 * @node: A pointer to the node for which sibling to find
 * Return: pointer to sibling node or NULL if the sibling does not exit.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node == node->parent->right)
		return (node->parent->left);
	return (node->parent->right);
}
