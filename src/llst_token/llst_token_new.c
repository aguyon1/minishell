/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_token_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:22:46 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/13 19:41:13 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_llist	*llst_token_new(t_type type, char *data)
{
	t_llist	*new_node;
	t_token	*new_token;

	new_token = token_new(type, data);
	new_node = llstnew(new_token);
	return (new_node);
}
