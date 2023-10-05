#include "binary_trees.h"
#include "limits.h"

/**
 * dr_is_bst_aid - Checks whether a binary tree is a valid binary search tree.
 * @tree: pointer to the root node of the tree to check.
 * @low: value of the smallest node visited this far.
 * @hi: value of the largest node visited this far.
 *
 * Valentine
 * Return: If the tree is a valid BST, 1, otherwise 0.
 */
int dr_is_bst_aid(const binary_tree_t *tree, int low, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > hi)
			return (0);
		return (dr_is_bst_aid(tree->left, low, tree->n - 1) &&
			dr_is_bst_aid(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (dr_is_bst_aid(tree, INT_MIN, INT_MAX));
}
