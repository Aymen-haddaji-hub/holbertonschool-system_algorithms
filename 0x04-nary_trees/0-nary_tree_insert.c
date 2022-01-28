#include "nary_trees.h"

/**
 * nary_tree_insert - Inserts a new node in a N-ary tree
 * @parent: Pointer to the parent node
 * @str: String to be inserted
 * Return: Pointer to the new node
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);

	new_node->content = strdup(str);
	if (!new_node->content)
	{
		free(new_node);
		return (NULL);
	}
	new_node->parent = parent;
	new_node->children = NULL;
	new_node->nb_children = 0;
	if (parent)
	{
	++parent->nb_children;
	new_node->next = parent->children;
	parent->children = new_node;
	}
	else
		new_node->next = NULL;
	return (new_node);
}
