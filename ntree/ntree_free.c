/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntree_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:22:19 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/13 17:25:23 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ntree.h"

void	ntree_free(t_ntree **ntree, t_del_fun del)
{
	t_ntree	*current_node;
	t_llist	*current;
	t_llist	*next;

	current_node = *ntree;
	if (current_node == NULL)
		return ;
	del(current_node->data);
	current = current_node->children;
	while (current != NULL)
	{
		next = current->next;
		ntree_free((t_ntree **)&(current->content), del);
		xfree(current);
		current = next;
	}
	xfree(current_node);
	*ntree = NULL;
}
