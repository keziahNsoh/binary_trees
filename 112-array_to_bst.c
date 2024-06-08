#include "binary_trees.h"

/**
 * array_to_bst - Build a Binary Search Tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of element in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
binary_tree_t *array_to_bst(int *array, size_t size)
{
	binary_tree_t *root = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (bst_insert(&root, array[i]) == NULL)
			return (NULL);
	}

	return (root);
}
