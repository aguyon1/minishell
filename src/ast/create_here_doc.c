/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:06:36 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/13 13:38:23 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_ntree	*create_here_end(t_llist *leaf_node)
{
	const t_token	*token = leaf_node->content;
	t_ntree			*new_leaf_content;
	t_llist			*new_leaf;
	char			*here_end;

	new_leaf_content = leaf_new(token);
	if (new_leaf_content == NULL)
		return (NULL);
	new_leaf = llstnew(new_leaf_content);
	if (new_leaf == NULL)
		return (ast_free(new_leaf_content), NULL);
	here_end = xstrdup(token->data);
	return (ast_new(HERE_END, here_end, new_leaf));
}

t_ntree	*create_here_doc(t_llist *begin, t_llist *end)
{
	t_llist	*children;
	t_llist	*child;

	(void)end;
	children = NULL;
	child = create_child(begin->next, create_here_end);
	if (child == NULL)
		return (NULL);
	llstadd_back(&children, child);
	return (ast_new(HERE_DOC, NULL, children));
}
