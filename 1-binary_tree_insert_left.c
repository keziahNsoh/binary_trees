#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - This inserts a node as the left child of another node
 * @parent: The pointer to the parent node
 * @value: Value to put in the new node
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (parent == NULL)
        return (NULL);

    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return (NULL);

    new_node->left = parent->left;
    if (new_node->left != NULL)
        new_node->left->parent = new_node;

    parent->left = new_node;

    return (new_node);
}
