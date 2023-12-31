/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:16:57 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/13 13:17:06 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static const char	*g_type[]
	= {
	"dummy",
	"or",
	"and",
	"pipe",
	"great",
	"less",
	"dgreat",
	"dless",
	"opening_parenthesis",
	"closing_parenthesis",
	"newline",
	"word",
	"error"
};

void	token_print(t_token *token)
{
	ft_printf("text : %s, type : %s\n", token->data, g_type[token->type]);
}
