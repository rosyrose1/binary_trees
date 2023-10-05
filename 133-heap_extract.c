#include "binary_trees.h"
#include "0-binary_tree_node.c"

/**
 * tree_height - calculates the height of a binary tree
 * @tree: A pointer to the root node of the tree
 * Return: The height of the tree or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t height_lf = 0;
	size_t height_rt = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_lf = 1 + tree_height(tree->left);

	if (tree->right)
		height_rt = 1 + tree_height(tree->right);

	if (height_lf > height_rt)
		return (height_lf);
	return (height_rt);
}
/**
 * tree_size_h - calculates the sum of heights of a binary tree
 * @tree: A pointer to the root node of the tree.
 * Return: The height of the tree or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t height_lf = 0;
	size_t height_rt = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_lf = 1 + tree_size_h(tree->left);

	if (tree->right)
		height_rt = 1 + tree_size_h(tree->right);

	return (height_lf + height_rt);
}

/**
 * _preorder - Traverse a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: A double pointer to store the last node visited.
 * @height: The height of the tree
 * Return: No Return value
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int val;
	heap_t *temp1, *temp2;

	if (!root)
		return;

	temp1 = root;

	while (1)
	{
		if (!temp1->left)
			break;
		if (!temp1->right)
			temp2 = temp1->left;
		else
		{
			if (temp1->left->n > temp1->right->n)
				temp2 = temp1->left;
			else
				temp2 = temp1->right;
		}
		if (temp1->n > temp2->n)
			break;
		val = temp1->n;
		temp1->n = temp2->n;
		temp2->n = val;
		temp1 = temp2;
	}
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int val;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	val = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (val);
	}

	_preorder(heap_r, &node, tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (val);
}
