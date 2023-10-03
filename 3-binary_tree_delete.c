#include "binary_trees.h"
/**
 * binary_tree_delete - Deletes an entire binary tree
 *
 * @tree: A pointer to the root of tyhe binary tree to be deleted
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	binary_tree_delete(tree->right);
	binary_tree_delete(tree->left);
	free(tree);
}
