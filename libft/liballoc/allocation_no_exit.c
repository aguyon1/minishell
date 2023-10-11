/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_no_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:11:21 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/10 22:41:27 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocation.h"

void	*xmalloc_no_exit(size_t size)
{
	t_memory_list	*node;

	node = memory_list_new(size, NULL);
	if (node == NULL)
		return (NULL);
	handle_memory_list(node, ALLOC);
	return (node->memory);
}

void	*xmalloc_dtor_no_exit(size_t size, void *dtor)
{
	t_memory_list	*node;

	node = memory_list_new(size, dtor);
	if (node == NULL)
		return (NULL);
	handle_memory_list(node, ALLOC);
	return (node->memory);
}
