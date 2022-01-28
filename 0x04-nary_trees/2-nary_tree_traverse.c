#include "nary_trees.h"

/**
 * nary_tree_traverse - Inserts a new node in a N-ary tree
 * @root: Pointer to the root node
 * @action: Pointer to the function to be called for each node
 * @depth: Depth of the tree
 */
size_t nary_tree_traverse(nary_tree_t const *root, void (*action)(nary_tree_t const *node, size_t depth))
{
	size_t depth = 0;

	if (!root)
		return (0);
	action(root, depth);
	depth++;
	for (nary_tree_t const *node = root->children; node; node = node->next)
		depth += nary_tree_traverse(node, action);
	return (depth);
}
