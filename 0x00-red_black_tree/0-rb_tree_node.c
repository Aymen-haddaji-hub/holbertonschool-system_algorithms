#include "rb_trees.h"

/**
 * rb_tree_node - creates a Red-Black Tree node.
 * @parent: pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * @color: color of the node.
 * Return: pointer to the new node, or NULL on failure.
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *new_node = NULL;

	new_node = malloc(sizeof(rb_tree_t));
	if (new_node == NULL)
		return (NULL);

	memset(new_node, 0, sizeof(*new_node));
	new_node->parent = parent;
	new_node->n = value;
	new_node->color = color;

	return (new_node);
}
