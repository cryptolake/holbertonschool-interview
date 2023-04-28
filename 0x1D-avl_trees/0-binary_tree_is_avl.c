#include "binary_trees.h"
#include <stdio.h>

/**
 * abs - absolute value
 * @num: number to get absolute value
 *
 * Return: absolute value
 **/
int abs(const int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

/**
 * is_BST - check if tree is bst
 * @tree: root node
 * @min: minimum value
 * @max: maximum value
 *
 * Return: 1 bst, 0 not bst
 **/
int is_BST(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_BST(tree->left, min, tree->n) &&
			is_BST(tree->right, tree->n, max));
}

/**
 * tree_height - get balance factor of tree
 * @tree: root node
 *
 * Return: tree_height
 **/
int tree_height(const binary_tree_t *tree)
{
	int right = 0, left = 0;

	if (tree == NULL)
		return (0);

	right = 1 + tree_height(tree->right);
	left = 1 + tree_height(tree->left);
	/* printf("left = %d\n", left); */
	/* printf("right = %d\n", right); */

	if (right > left)
		return (right);
	return (left);
}

/**
 * is_balanced - check if tree is balanced
 * @tree: tree to check
 *
 * Return: 1 balanced, 0 balanced
 **/
int is_balanced(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (abs(tree_height(tree->right) - tree_height(tree->left)) > 1)
		return (0);

	return (is_balanced(tree->right) && is_balanced(tree->left));
}

/**
 * binary_tree_is_avl - Check if tree is AVL
 * @tree: tree to check
 *
 * Return: 1 if avl 0 if not
 **/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (is_BST(tree, MIN, MAX) && is_balanced(tree))
		return (1);
	return (0);
}
