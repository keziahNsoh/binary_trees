#include "binary_trees.h"
#include <stdlib.h>

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
 * binary_tree_balance - Measure the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: The balance factor of the binary tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) -
			binary_tree_height(tree->right));
}

/**
 * avl_insert - Insert a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL Tree to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
binary_tree_t *avl_insert(binary_tree_t **tree, int value)
{
	binary_tree_t *new_node;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{ (*tree)->left = avl_insert(&(*tree)->left, value);
		if (binary_tree_balance(*tree) > 1 && value < (*tree)->left->n)
			*tree = binary_tree_rotate_right(*tree);
		else if (binary_tree_balance(*tree) > 1 && value > (*tree)->left->n)
		{ (*tree)->left = binary_tree_rotate_left((*tree)->left);
			*tree = binary_tree_rotate_right(*tree); }
	}
	else if (value > (*tree)->n)
	{ (*tree)->right = avl_insert(&(*tree)->right, value);
		if (binary_tree_balance(*tree) < -1 && value > (*tree)->right->n)
			*tree = binary_tree_rotate_left(*tree);
		else if (binary_tree_balance(*tree) < -1 && value < (*tree)->right->n)
		{ (*tree)->right = binary_tree_rotate_right((*tree)->right);
			*tree = binary_tree_rotate_left(*tree);
		}
	}
	else
		return (NULL);

	return (*tree);
}
