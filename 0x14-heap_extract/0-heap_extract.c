#include "binary_trees.h"

/**
* get_down - get the root to the last element.
* @root: root
* Return: last elemnt
*/
heap_t *get_down(heap_t *root)
{
	heap_t *child;
	int n;

	if (root->left == NULL && root->right == NULL)
	{
		return (root);
	}
	if (root->left &&
		(!root->right || root->left->n >= root->right->n))
		child = root->left;
	else
		child = root->right;
	n = root->n;
	root->n = child->n;
	child->n = n;
	return (get_down(child));
}

/**
* heap_rebalance - rebalance heap by checking if
* left nodes have more or the same nodes as right nodes
* @root: root of heap
**/
void heap_rebalance(heap_t *root)
{
	heap_t *lchild = root->left, *rchild = root->right;

	if (lchild == NULL || rchild == NULL)
		return;

	if (lchild->left == NULL && rchild->left != NULL)
	{
		lchild->left = rchild->left;
		rchild->left->parent = lchild;
		rchild->left = NULL;
	}
	if (lchild->right == NULL && rchild->right != NULL)
	{
		lchild->right = rchild->right;
		rchild->right->parent = lchild;
		rchild->right = NULL;
	}
	heap_rebalance(root->left);
	heap_rebalance(root->right);
}

/**
 * heap_extract - extract root and re organize tree
 * @root: root of tree
 * Return: return value of root
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	int n;

	if (root == NULL || *root == NULL)
		return (0);
	last = get_down(*root);
	n = last->n;
	if (last->parent->right == last)
		last->parent->right = NULL;
	else
		last->parent->left = NULL;
	free(last);
	heap_rebalance(*root);
	return (n);
}
