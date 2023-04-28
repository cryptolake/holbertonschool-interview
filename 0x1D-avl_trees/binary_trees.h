#ifndef AVL
#define AVL
#define MIN (-2147483647 - 1)
#define MAX	2147483647
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;
#include <stdlib.h>
#include <stdio.h>

void binary_tree_print(const binary_tree_t *tree);
int binary_tree_is_avl(const binary_tree_t *tree);

binary_tree_t *binary_tree_node(const binary_tree_t *tree, int n);

#endif
