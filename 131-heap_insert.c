#include "binary_trees.h"

/**
 * heap_insert - inserting a value in Max Binary Heap
 * @root: a double pointer to the root node of the Heap
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *turn;
	int size, leaves, sub, bit, level, temp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;
	
/*
* Traverse tree to first empty slot based on the binary
* representation of the number of leaves.
*/
	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	turn = new;
	for (; turn->parent && (turn->n > turn->parent->n); turn = turn->parent)
	{
		temp = turn->n;
		turn->n = turn->parent->n;
		turn->parent->n = temp;
		new = new->parent;
	}
	return (new);
}

/**
 * binary_tree_size - calculates the size of a binary tree
 * @tree: tree to calculate.
 * Return: size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
