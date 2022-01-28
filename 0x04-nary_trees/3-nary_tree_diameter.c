#include "nary_trees.h"

/**
* maxdepth - returns max depth of a tree
* @root: pointer to root node
* @diameter: pointer to max dimaeter
* Return: returns max depth of a tree
*/
size_t maxdepth(nary_tree_t const *root, size_t *diameter)
{
	nary_tree_t *tmp;
	size_t i = 0, j = 0, max_depth;

	if (!root)
		return (0);
	for (tmp = root->children; tmp; tmp = tmp->next)
	{
		max_depth = maxdepth(tmp, diameter);
		if (i < max_depth)
		{
			j = i;
			i = max_depth;
		}
		else if (j < max_depth)
			j = max_depth;
	}
	if (*diameter < i + j)
		*diameter = *diameter;
	*diameter = i + j;
	return (i + 1);
}
/**
 * nary_tree_diameter - Finds the diameter of a N-ary tree
 * @root: Pointer to the root node
 * Return: the diameter of the tree pointed to by root
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t diameter = 0;

	if (!root)
		return (0);
	maxdepth(root, &diameter);
	return (diameter + 1);
}
