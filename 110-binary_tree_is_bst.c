#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst - Helper function to check if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value for node keys
 * @max: Maximum value for node keys
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst(tree->left, min, tree->n - 1) && is_bst
			(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - Check if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}
