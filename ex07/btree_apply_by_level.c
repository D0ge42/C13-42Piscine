/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:37:10 by lonulli           #+#    #+#             */
/*   Updated: 2024/08/29 18:37:12 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>

//First argument = node's item;
//Second argument =  level on which we find: 0, for root. || 1 for children || 2 for grand-children etc.
//Third argument = 1 if first node, 0 otherwise.
// HOw to browse tree by levels?


int tree_height(t_btree *root)
{
	if(root == NULL)
		return 0;
	else
	{
		int left_height = tree_height(root->left);
		left_height++;
		int right_height = tree_height(root->right);
		right_height++;
		if(left_height < right_height) 	
			return right_height;
		else
		 return left_height;
	}
}

void print_level(t_btree *root, int clevel)
{
	if(!root)
		return;
	if(clevel == 0)
		printf("%s ",(char *)root->item);
	else
	{
		print_level(root->left, clevel - 1);
		print_level(root->right, clevel - 1);
	}
}

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	//Height of the tree.
	int tree_h = tree_height(root);
	//Base case
	if(!root)
		return ;
	//If it's the first element
	if(tree_h == 0 )
		(*applyf)(root->item, 0, 1);
	else
	{
	}
}

t_btree	*btree_create_node(void *item)
{
	t_btree	*new;

	new = (t_btree *)malloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->item = item;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
int main()
{
	t_btree *new1 = btree_create_node("3");
	new1->left = btree_create_node("1");
	new1-> right = btree_create_node("2");
	new1->left->left = btree_create_node("4");
	new1->left->left->left = btree_create_node("5");
	new1->left->left->left->left = btree_create_node("6");
	new1->right->right = btree_create_node("9");
}
