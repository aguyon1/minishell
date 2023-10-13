/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:42:24 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/13 17:30:53 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token	*token_dup(t_token *token)
{
	t_token	*new;

	new = xmalloc(sizeof(t_token));
	if (new == NULL)
		return (NULL);
	new->type = token->type;
	new->data = xstrdup(token->data);
	if (new->data == NULL)
		return (xfree(new), NULL);
	return (new);
}
