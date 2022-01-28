#include "nary_trees.h"

/**
 * nary_tree_delete - Deletes a node from a N-ary tree
 * @tree: Pointer to the node to be deleted
 * Return: void
 */
void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *tmp;

	if (!tree)
		return;
	while (tree->children)
	{
		tmp = tree->children;
		tree->children = tree->children->next;
		nary_tree_delete(tmp);
	}
	free(tree->content);
	free(tree);
}
