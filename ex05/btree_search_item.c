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

//Q: Why found becomes true when a match is found?
//A: Because the function cmpf(root->item, data,ref ) == 0 is true.
//Q: Why is function constatly returning found. 
//A: Its returning found constantly for each call stack remaining.
//Q: Why do we need return root->item . 
//A: We need it to return the root->item when found.
#include "ft_btree.h"
#include <string.h>
#include <stdio.h>

void	*btree_search_item(t_btree *root, void *data_ref,
						int (*cmpf)(void *, void *))
{
	void	*found;

	if (root == NULL)
		return (NULL);
	found = btree_search_item(root->left, data_ref, cmpf);
	if (found)
		return (found);
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root->item);
	return (btree_search_item(root->right, data_ref, cmpf));
}
/*int cmpf(void *a, void *b)
{
	return strcmp((char *)a, (char *)b);
}

void print_tree(t_btree *root)
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


	t_btree *new = btree_search_item(new1,"5",cmpf);
	if (new != NULL)
		printf("Found node with value %s\n", (char *)new);
	else
	 printf("Node with string %s not found \n", "5");


}

 	     3
	    / \
       1   2
      /     \
     4	     9
    /
   5
  /
 6
*/
