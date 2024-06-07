#include "binary_trees.h"

/**
 * binary_tree_nodes - Count the nodes in a binary tree
 * @tree: Pointer to the root node of the tree to count
 *
 * Return: The number of nodes in the binary tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;

	return 1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
}

/**
 * binary_tree_height - Measure the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: The height of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    if (left_height > right_height)
	    return (left_height + 1);
    else
	    return (right_height + 1);
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = binary_tree_height(tree);
	size_t nodes = binary_tree_nodes(tree);

    /* A perfect binary tree should have 2^h - 1 nodes */
	if (nodes == ((size_t)(1 << height) - 1))
		return (1);

	return (0);
}
