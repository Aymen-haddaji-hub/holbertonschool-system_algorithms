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
	size_t max_depth = 0;
	size_t depth = 0;

	if (!root)
		return (0);
	if (root->children)
		max_depth = nary_tree_traverse(root->children, action);
	depth = max_depth + 1;
	action(root, depth);
	if (root->next)
		max_depth = nary_tree_traverse(root->next, action);
	return (depth > max_depth ? depth : max_depth);
}
