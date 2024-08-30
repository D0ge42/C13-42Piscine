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

void btree_insert_data(t_btree **root, void *item, int(*cmpf)(void *, void *))
{
	t_btree *newtree;

	if(root == NULL || item == NULL)
		return ;
	if (*root == NULL) //If *root is empty.
		*root = btree_create_node(item);
	return;
	newtree = *root;
	if ((*cmpf)(item, (*root)->item) < 0)
	{
		if(newtree->left) 
			btree_insert_data(&newtree->left, item, cmpf);
		else
		 newtree->left = btree_create_node(item);
	}
	else 
	{
		if(newtree->right)
			btree_insert_data(&newtree->right, item, cmpf);
		else
		 newtree->left = btree_create_node(item);	
	}
}

void print_tree(t_btree *root)
{
    if (root)
    {
        print_tree(root->left);
        printf("%s ", (char *)root->item);
        print_tree(root->right);
    }
}

int main()
{

	t_btree *tree = btree_create_node("20");
	tree->left = btree_create_node("30");
	tree->right = btree_create_node("40");
	tree->left->left = btree_create_node("50");
	print_tree(tree);
	printf("\n");
}
