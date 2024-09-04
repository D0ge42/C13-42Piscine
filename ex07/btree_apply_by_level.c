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

int max (int a, int b)
{
    if(a >= b)
	return a;
    else
     return b;
}

int tree_height(t_btree *root)
{
    if(!root)
	return 0;
    else
    {
	int depth1 = tree_height(root->left);
	int depth2 = tree_height(root->right);
	return max(depth1, depth2)+ 1;
    } 
}

//Ho l'altezza totale dell'albero.
//Ora devo applicare la funzione livello per livello.
//

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int clevel, int isfirst))
{
    int tree_h = tree_height(root);


}


int main()
{
    t_btree *node = btree_create_node("0");
    node->left = btree_create_node("1");
    node->left->left = btree_create_node("2");
    node->right = btree_create_node("5");
    node->right->right = btree_create_node("2");
    printf("Tree height %d\n", tree_height(node));

}
