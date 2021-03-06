#include "rb_trees.h"

/**
 * array_to_rb_tree -builds a Binary Search Tree from an array.
 * @array: pointer to first element of array to be converted
 * @size: number of elements in array
 * Return: pointer to root node of generated red-black tree, NULL on failure
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	size_t i;
	rb_tree_t *root;

	root = NULL;
	for (i = 0; array && i < size; ++i)
		rb_tree_insert(&root, array[i]);
	return (root);
}
