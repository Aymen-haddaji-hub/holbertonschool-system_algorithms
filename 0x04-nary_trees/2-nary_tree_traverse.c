#include "nary_trees.h"

/**
 * nary_tree_traverse - Inserts a new node in a N-ary tree
 * @root: Pointer to the root node
 * @action: Pointer to the function to be called for each node
 * Return: the maximum depth of the tree
 */
size_t nary_tree_traverse(nary_tree_t const *root,
		void (*action)(nary_tree_t const *node, size_t depth))
{
	static size_t depth, max_depth;
	size_t i;

	while (root)
	{
		action(root, depth);
		++depth;
		nary_tree_traverse(root->children, action);
		root = root->next;
	}
	if (max_depth < depth)
		max_depth = depth;
	if (depth == 0)
	{
		i = max_depth;
		max_depth = 0;
	}
	else
		--depth;
	return (i);
}
