#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - Measure the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: The size of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t size = binary_tree_size(tree);

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * size);

	if (queue == NULL)

		return (0);

	size_t index = 0;

	queue[index++] = (binary_tree_t *)tree;

	while (index < size)
	{
		binary_tree_t *current = queue[index - 1];

		if (current->left != NULL)

			queue[index++] = current->left;

		if (current->right != NULL)

		queue[index++] = current->right;

	if (current->left == NULL && current->right == NULL)
		break;
	}

	while (index > 0 && queue[index - 1] == NULL)
		index--;

	free(queue);

	return (index == 0);
}
