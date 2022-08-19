#include "binary_trees.h"

/**
 * swap_fam - swap child and parent
 * @p: parent node
 * @c: child node
 **/
void swap_fam(heap_t *p, heap_t *c)
{
	heap_t *cl = c->left, *cr = c->right;

	c->parent = p->parent;
	if (p->parent)
	{
		if (p->parent->left == p)
			p->parent->left = c;
		if (p->parent->right == p)
			p->parent->right = c;
	}

	if (p->left == c)
	{
		if (p->right)
			p->right->parent = c;
		c->left = p;
		c->right = p->right;
	}
	else if (p->right == c)
	{
		if (p->left)
			p->left->parent = c;
		c->right = p;
		c->left = p->left;
	}
	p->parent = c;
	p->right = cr;
	p->left = cl;
	if (cl != NULL)
		cl->parent = p;
	if (cr != NULL)
		cr->parent = p;
}

/**
 * heapify - put node in the correct place
 * @root: root node
 * @node: node
 * Return: node
 **/
heap_t *heapify(heap_t **root, heap_t *node)
{
	if (node->parent == NULL)
	{
		*root = node;
		return (node);
	}
	if (node->n > node->parent->n)
	{
		swap_fam(node->parent, node);
		return (heapify(root, node));
	}
	else
	{
		return (node);
	}
}

/**
 * binary_tree_height - binary tree height
 * @tree: node to get height from
 * Return: height
 **/
size_t binary_tree_height(const heap_t *tree)
{
	size_t ld = 0, rd = 0;

	if (!tree)
		return (0);
	ld = binary_tree_height(tree->left);
	rd = binary_tree_height(tree->right);

	if (ld <= rd)
		return (ld + 1);

	return (rd + 1);
}

/**
 * add_node - add node to end of heap
 * @root: root node
 * @node: node to add
 * Return: node added
 **/
heap_t *add_node(heap_t *root, heap_t *node)
{
	if (binary_tree_height(root->left) <= binary_tree_height(root->right))
	{
		if (root->left == NULL)
		{
			root->left = node;
			node->parent = root;
			return (root->left);
		}
		return (add_node(root->left, node));
	}

	else
	{
		if (root->right == NULL)
		{
			root->right = node;
			node->parent = root;
			return (root->right);
		}
		return (add_node(root->right, node));
	}

}

/**
 * heap_insert - insert node into binary max-heap
 * @root: root node
 * @value: value of new node
 * Return: new node
 **/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;

	if (root == NULL)
		return (NULL);

	node = malloc(sizeof(heap_t));
	if (!node)
		return (NULL);
	node->n = value;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;

	if (*root == NULL)
	{
		*root = node;
		return (node);
	}

	node = add_node(*root, node);

	return (heapify(root, node));
}
