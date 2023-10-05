#include "binary_trees.h"

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: a double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node
 * Otherwise NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaf, sub, bit, index, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaf = size;
	for (index = 0, sub = 1; leaf >= sub; sub *= 2, index++)
		leaf -= sub;

	for (bit = 1 << (index - 1); bit != 1; bit >>= 1)
		tree = leaf & bit ? tree->right : tree->left;

	new = binary_tree_node(tree, value);
	leaf & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}

	return (new);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: 0 if tree is NULL, otherwise the size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_ht, right_ht;

	if (tree == NULL)
		return (0);
	left_ht = binary_tree_size(tree->left);
	right_ht = binary_tree_size(tree->right);

	return (left_ht + 1 + right_ht);
}
