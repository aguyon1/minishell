/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:45:03 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/13 19:40:25 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_ntree	*create_cmd_name(t_llist *leaf_node)
{
	const t_token	*token = leaf_node->content;
	t_ntree			*new_leaf_content;
	t_llist			*new_leaf;

	new_leaf_content = leaf_new(token);
	new_leaf = llstnew(new_leaf_content);
	return (ast_new(CMD_NAME, NULL, new_leaf));
}

t_llist	*find_cmd_name(t_llist	*begin, t_llist *end)
{
	t_llist	*current;

	if (is_token_word(begin->content))
		return (begin);
	current = begin->next;
	while (current != NULL && current != end)
	{
		if (is_token_word(current->content) \
			&& !is_token_redirection(current->prev->content))
			return (current);
		current = current->next;
	}
	return (end);
}
