#include "binary_trees.h"

/**
 * array_to_bst -Constructs a binary search tree from an array.
 * @array: pointer to the first element of the array to be converted.
 * @size:  number of elements in @array.
 * Return: A pointer to the root node of the created BST, or NULL upon failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t r, d;

	if (array == NULL)
		return (NULL);

	for (r = 0; r < size; r++)
	{
		for (d = 0; d < r; d++)
		{
			if (array[d] == array[r])
				break;
		}
		if (d == r)
		{
			if (bst_insert(&tree, array[r]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
