#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_find_insert_position - Find the position to insert a value in a BST
 * @tree: Pointer to the root node of the BST
 * @value: Value to insert
 *
 * Return: Pointer to the parent node where insertion should occur,
 * or NULL if @tree is NULL
 */
static binary_tree_t *bst_find_insert_position(binary_tree_t *tree, int value)
{
	binary_tree_t *current = tree;
	binary_tree_t *parent = NULL;

	while (current != NULL)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
			return (NULL);
	}

	return (parent);
}

/**
 * bst_perform_insertion - Insert a value into a BST at the given position
 * @parent: Pointer to the parent node where insertion should occur
 * @value: Value to insert
 *
 * Return: Pointer to the newly inserted node, or NULL on failure
 */
static binary_tree_t *bst_perform_insertion(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}

/**
 * bst_insert - Insert a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
binary_tree_t *bst_insert(binary_tree_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = bst_perform_insertion(NULL, value);

		return (*tree);
	}

	binary_tree_t *parent = bst_find_insert_position(*tree, value);

	if (parent == NULL)
		return (NULL);

	return (bst_perform_insertion(parent, value));
}
