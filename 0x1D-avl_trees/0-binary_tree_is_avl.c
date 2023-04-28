#include "binary_trees.h"

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
	if (tree->n < min || tree->n > max)
		return (0);

	return (is_BST(tree->left, min, tree->n - 1) &&
			is_BST(tree->right, tree->n + 1, max));
}

/**
 * balance_factor - get balance factor of tree
 * @tree: root node
 *
 * Return: balance factor
 **/
int balance_factor(const binary_tree_t *tree)
{
	int right = 0, left = 0;

	if (tree == NULL)
		return (0);

	right = 1 + balance_factor(tree->right);
	left = 1 + balance_factor(tree->left);

	return (abs(right - left));
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
	if (is_BST(tree, MIN, MAX) && balance_factor(tree) <= 1)
		return (1);
	return (0);
}
