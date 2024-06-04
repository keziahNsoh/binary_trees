#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_is_leaf - This checks if a node is a leaf
 * @node: A pointer to the node to check
 * Return: 1 if node is a leaf, 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	return (node->left == NULL && node->right == NULL);
}
