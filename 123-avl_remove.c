#include "binary_trees.h"

/**
 * bal - Calculates balance factor of a AVL
 * @tree: A pointer to the AVL tree node.
 * Return: The balance factor of the AVL tree node.
 */
void bal(avl_t **tree)
{
	int bal_value;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bal_value = binary_tree_balance((const binary_tree_t *)*tree);
	if (bal_value > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bal_value < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor -Find the minimum node in the right subtree.
 * @node: A pointerv to the node to find the successor for.
 * Return: The value of the minimum node in the right subtree
 */
int successor(bst_t *node)
{
	int lf = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		lf = successor(node->left);
		if (lf == 0)
		{
			return (node->n);
		}
		return (lf);
	}

}
/**
 *remove_type - removeing a node depending of children it has.
 *@root: A pointer to the node to remove
 *Return: 0 if it has no children or a different value if it has children
 */
int remove_type(bst_t *root)
{
	int nw_val = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		nw_val = successor(root->right);
		root->n = nw_val;
		return (nw_val);
	}
}
/**
 * bst_remove - remove a node from a specific value from a BST tree
 * @root: A pointer to the root of the BST
 * @value: The value to remove from BST
 * Return: A pointer to the modified BST after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int jq = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		jq = remove_type(root);
		if (jq != 0)
			bst_remove(root->right, jq);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: A pointer to the root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
