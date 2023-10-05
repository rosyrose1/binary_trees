#include "binary_trees.h"
/**
 * binary_tree_levelorder - Navigates through a binary tree
 * using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: the function to call
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *list[1024];
	binary_tree_t *tmp;
	int r = 0, d = 0;

	if (tree == NULL || func == NULL)
		return;
	for (r = 0; r < 1024; r++)
		list[r] = NULL;
	list[0] = (binary_tree_t *)tree;
	r = 0;
	while (list[r] != NULL)
	{
		tmp = list[r];
		func(tmp->n);
		if (tmp->left != NULL)
		{
			d++;
			list[d] = tmp->left;
		}
		if (tmp->right != NULL)
		{
			d++;
			list[d] = tmp->right;
		}
		r++;
	}
}
