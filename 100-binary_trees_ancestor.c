#include "binary_trees.h"
/**
 * binary_trees_ancestor - Finds the lowest common ancester of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 * Return: pointer to the lowest common ancester node or NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
										const binary_tree_t *second)
{
	binary_tree_t *node;

	if (first == NULL || second == NULL)
		return (NULL);
	node = (binary_tree_t *)second;
	while (first != NULL)
	{
		while (second)
		{
			if (first == second)
				return ((binary_tree_t *)first);
			second = second->parent;
		}
		second = node;
		first = first->parent;
	}
	return (NULL);
}
