#include "binary_trees.h"

/**
 * tree_size - measures the total height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size(tree->left);

	if (tree->right)
		height_r = 1 + tree_size(tree->right);

	return (height_l + height_r);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a
 * sorted array of integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * rosy and dede's task
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int y, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (y = 0; heap; y++)
		a[y] = heap_extract(&heap);

	return (a);
}

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: pointer to the parent of the node to create.
 * @value: value to put in the new node.
 * Return: If an error occurs - NULL.
 * Otherwise - a pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *current;

	current = malloc(sizeof(binary_tree_t));
	if (current == NULL)
		return (NULL);
	current->n = value;
	current->parent = parent;
	current->left = NULL;
	current->right = NULL;
	return (current);
}
