#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);

		return (*tree);
	}

	bst_t *current = *tree;

	while (1)
	{
		if (value < current->n)
		{
			if (current->left == NULL)
			{
				current->left = binary_tree_node(current, value);

				return (current->left);
			}
			else
			{
				current = current->left;
			}
		}
		else if (value > current->n)
		{
			if (current->right == NULL)
			{
				current->right = binary_tree_node(current, value);

				return (current->right);
			}
			else
			{
				current = current->right;
			}
		}
		else
		{ return (NULL); }
	}
}
