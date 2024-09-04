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
#include <ctype.h>
#include <stdio.h>

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

void print_tree(void *item, int current_level, int is_first_elem)
{
	printf("Item : %s, current level %d, Is first element %d\n", item, current_level, is_first_elem);
}

void call(t_btree *root, int current_level, int *levels, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	is_first_item;
	if(levels[is_first_item] == 1)
		is_first_item = 0;
	else
	 levels[current_level] = 1;
	applyf(root->left, current_level, is_first_item);
	if(root->left)
		call(root->left, current_level + 1, levels, applyf);
	if(root->right)
		call(root->right,current_level + 1, levels, applyf);
}

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	count;
	int *levels;
	int 	i;

	if(!root)
		return ;
	count = tree_height(root);
	levels = (int *)malloc(sizeof(int) * count);
	if(!levels)
		return;
	i = 0;
	while(i < count)
		levels[i++] = 0;
	call(root, 0, levels, applyf);
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
	btree_apply_by_level(new1, print_tree);
}
