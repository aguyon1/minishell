/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:42:24 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/13 19:37:14 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token	*token_dup(t_token *token)
{
	t_token *const	new = xmalloc(sizeof(t_token));

	new->type = token->type;
	new->data = xstrdup(token->data);
	return (new);
}
