/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:48:23 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/10 22:45:27 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocation.h"

void	handle_memory_list(t_memory_list *node, t_alloc_flag flag)
{
	static t_memory_list	*memory_list = NULL;

	if (flag & ALLOC)
		memory_list_add(&memory_list, node);
	else if (flag & FREEALL)
		memory_list_clear(&memory_list);
	else if (flag & FREE)
		memory_list = node;
}

void	memory_list_add(t_memory_list **mlist, t_memory_list *node)
{
	node->next = *mlist;
	if (*mlist != NULL)
		(*mlist)->prev = node;
	*mlist = node;
}

t_memory_list	*memory_list_new(size_t size, void *dtor)
{
	t_memory_list	*new;

	new = malloc(sizeof(t_memory_list) + size - 1);
	if (new == NULL)
		return (NULL);
	*new = (t_memory_list){.prev = NULL, .next = NULL, .dtor = dtor};
	return (new);
}

void	memory_list_clear(t_memory_list **list)
{
	t_memory_list	*current;
	t_memory_list	*next;

	current = *list;
	while (current != NULL)
	{
		next = current->next;
		if (current->dtor)
			current->dtor(current->memory);
		free(current);
		current = next;
	}
	*list = NULL;
}

t_memory_list	*memory_list_get_node(void *memory)
{
	return (memory - offsetof(t_memory_list, memory));
}
