#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

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
 * enqueue - Add a node to the end of the queue
 * @queue: Pointer to the queue
 * @node: Pointer to the node to add
 */
void enqueue(binary_tree_t **queue, binary_tree_t *node)
{
	binary_tree_t **temp = queue;

	while (*temp != NULL)
		temp = &(*temp)->right;

	*temp = node;
}

/**
 * dequeue - Remove and return the front node of the queue
 * @queue: Pointer to the queue
 *
 * Return: Pointer to the front node of the queue
 */
binary_tree_t *dequeue(binary_tree_t **queue)
{
	binary_tree_t *front = *queue;

	if (*queue != NULL)
		*queue = (*queue)->right;

	return (front);
}

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node. The value in the node
 * must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *queue = NULL;
	const binary_tree_t *temp;

	if (tree == NULL || func == NULL)
		return;

	enqueue(&queue, (binary_tree_t *)tree);

	while (queue != NULL)
	{
		temp = dequeue(&queue);
		func(temp->n);

		if (temp->left != NULL)
			enqueue(&queue, (binary_tree_t *)temp->left);

		if (temp->right != NULL)
			enqueue(&queue, (binary_tree_t *)temp->right);
	}
}
