#include "rb_trees.h"

/**
* binary_tree_depth - measures the depth of a node in a binary tree
* @tree: node to check
* Return: depth
*/

size_t binary_tree_depth(const rb_tree_t *tree)
{
	int cont = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent != NULL)
	{
		cont++;
		tree = tree->parent;
	}
	return (cont);
}
/**
* binary_tree_is_none - checks if a node is a leaf
* @node: parent node
* Return: pointer to the new node
*/

int binary_tree_is_none(const rb_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
/**
* _insert - function to insert node
* @tree: pointer to tree
* @level: level to insert node
* @value: value of the new node
* Return: the node inserted
*/

rb_tree_t *_insert(rb_tree_t *tree, size_t level, int value)
{
	rb_tree_t *left, *right;

	if (tree == NULL)
		return (NULL);
	if (binary_tree_depth(tree) == level)
	{
		if (binary_tree_is_none(tree))
			return (tree->left = rb_tree_node(tree, value, RED));
		if (tree->left != NULL && tree->right == NULL)
			return (tree->right = rb_tree_node(tree, value, RED));
		return (NULL);
	}
	left = _insert(tree->left, level, value);
	if (left == NULL)
		right = _insert(tree->right, level, value);
	else
		return (left);
	return (right);
}

/**
* binary_tree_height - measures the height of a binary tree
* @tree: node to check
* Return: height
*/

size_t binary_tree_height(const rb_tree_t *tree)
{
	int lheight;
	int rheight;

	if (tree == NULL || binary_tree_is_none(tree) == 1)
		return (0);
	lheight = binary_tree_height(tree->left);
	rheight = binary_tree_height(tree->right);

	if (lheight >= rheight)
		return (1 + lheight);
	return (1 + rheight);
}

/**
* rb_tree_insert - binary tree node
* @tree: pointer to the tree node
* @value: value store to inserted
* Return: the inserted node
*/

rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	size_t level, i, tmp = 0;
	rb_tree_t *node = NULL;

	if (*tree == NULL)
	{
		*tree = rb_tree_node((rb_tree_t *)*tree, value, BLACK);
		return (*tree);
	}
	level = binary_tree_height(*tree);
	for (i = 0; i <= level; i++)
	{
		node = (rb_tree_t *) _insert((rb_tree_t *)*tree, i, value);
		if (node != NULL)
			break;
	}
	while (node->parent && node->parent->color == RED)
	{
		tmp = node->parent->n;
		node->parent->n = node->n;
		node->n = tmp;
		node = node->parent;
	}
	return (node);
}
