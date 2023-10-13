/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:27:36 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/12 15:56:48 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	btree_free(t_btree *root, void (*del)(void *))
{
	if (root == NULL)
		return ;
	del(root->item);
	free(root);
	btree_free(root->right, del);
	btree_free(root->left, del);
}
