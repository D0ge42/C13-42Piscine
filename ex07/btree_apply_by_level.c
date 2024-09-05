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

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	tree_height(t_btree *root)
{
	int depth1;
	int depth2;
    if (!root)
		return 0;
    else
    {
		depth1 = tree_height(root->left);
		depth2 = tree_height(root->right);
		return (max(depth1, depth2) + 1);
    } 
}

void level_by_level(t_btree *root, int clevel,int *levels,
		    void(*applyf)(void *item, int clevel, int isfirst))
{
    int	first_item;

    if (root == NULL)
	return ;
    if(levels[clevel] == 1)
	first_item = 0;
    else
    {
	levels[clevel] = 1;
	first_item = 1;
    }
	(*applyf)(root->item, clevel, first_item);
	level_by_level(root->left, clevel + 1, levels, applyf);
	level_by_level(root->right,clevel + 1, levels, applyf);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int clevel, int isfirst))
{
    if(root == 0)
	return;
    int tree_h = tree_height(root);
    int *levels = (int *)malloc(sizeof(int) * tree_h);
    int i = 0;
    while(i < tree_h)
	levels[i++] = 0;
    level_by_level(root, 0, levels, applyf);
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
void print_levels(void *item, int clevel, int isfirst)
{
    printf("Item : %s, current level: %d, is_first %d\n", (char *)item, clevel, isfirst);
}
int main()
{
    t_btree *node = btree_create_node("0");
    node->left = btree_create_node("1");
    node->left->left = btree_create_node("3");
    node->left->left->left = btree_create_node("9");
    node->right = btree_create_node("5");
    node->right->right = btree_create_node("2");
    node->right->right->right = btree_create_node("8");
    node->right->right->right->right = btree_create_node("7");
    btree_apply_by_level(node, print_levels);
}
//             0
//            / \
//           1   5
//          /     \
//         3       2
//        /         \
//       9           8
//                    \
//                     7
//
*/
