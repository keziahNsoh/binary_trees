#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_min_value - Find the minimum value node in a Binary Search Tree
 * @node: Pointer to the root node of the BST
 *
 * Return: Pointer to the node containing the minimum value
 */
binary_tree_t *bst_min_value(binary_tree_t *node)
{
	while (node->left != NULL)
		node = node->left;

	return (node);
}

/**
 * bst_remove - Remove a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of
 * the tree after removing the desired value
 */
binary_tree_t *bst_remove(binary_tree_t *root, int value)
{
	binary_tree_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = bst_min_value(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
