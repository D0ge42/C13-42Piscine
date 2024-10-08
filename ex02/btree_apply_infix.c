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

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root->left)
		btree_apply_infix(root->left, applyf);
	(*applyf)(root->item);
	if (root->right)
		btree_apply_infix(root->right, applyf);
}
/*t_btree	*btree_create_node(void *item)
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
void display(void *a)
{
	printf("%s ",(char *)a);
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

	btree_apply_infix(new1,display);

}*/
