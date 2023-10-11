/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:42:38 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/10 22:45:54 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocation.h"

void	*xmalloc(size_t size)
{
	t_memory_list	*node;

	node = memory_list_new(size, NULL);
	if (node == NULL)
		exit(EXIT_FAILURE);
	handle_memory_list(node, ALLOC);
	return (node->memory);
}

void	*xmalloc_dtor(size_t size, void *dtor)
{
	t_memory_list	*node;

	node = memory_list_new(size, dtor);
	if (node == NULL)
		exit(EXIT_FAILURE);
	handle_memory_list(node, ALLOC);
	return (node->memory);
}

void	xfree_all(void)
{
	handle_memory_list(NULL, FREEALL);
}

void	xfree(void *ptr)
{
	t_memory_list	*node;
	t_memory_list	*prev;
	t_memory_list	*next;

	if (ptr == NULL)
		return ;
	node = memory_list_get_node(ptr);
	prev = node->prev;
	next = node->next;
	if (node->dtor)
		node->dtor(node->memory);
	free(node);
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	if (prev == NULL)
		handle_memory_list(next, FREE);
}
