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

int	btree_level_count(t_btree *root)
{
	int	i;
	int	j;

	if (root)
	{
		i = btree_level_count(root->left);
		i++;
		j = btree_level_count(root->right);
		j++;
		if (i < j)
			return (j);
		else
			return (i);
	}
	else
		return (0);
}

/*void print_tree(t_btree *root)
{
	if(root)
	{
		print_tree(root->left);
		printf("%s ", (char *)root->item);
		print_tree(root->right);
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

	printf("Greatest subtree has size %i\n", btree_level_count(new1));

}*/
