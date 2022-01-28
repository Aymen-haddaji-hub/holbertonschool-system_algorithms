#include "nary_trees.h"

/**
 * path_exists - Checks if a path exists between two nodes
 * @root: Pointer to the root node
 * @path: Pointer to the path
 * Return: 1 if path exists, 0 otherwise
 */
int path_exists(nary_tree_t const *root, char const * const *path)
{
	size_t i;

	if (!root || !path || !*path)
		return (0);
	for (i = 0; path[i]; ++i, root = root->children)
	{
		while (root && strcmp(root->content, path[i]) != 0)
			root = root->next;
		if (!root)
			return (0);
	}
	return (1);
}
