/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:01:21 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/13 13:32:30 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	print_data(t_token *token)
{
	ft_printf("%s", type_to_string(token->type));
	if (token->data == NULL)
		return ;
	if (token->type == REDIRECTION || token->type == HERE_DOC)
		ft_printf(": %d", (intptr_t)token->data);
	else if (token->type == PIPELINE)
		ft_printf(": %p", token->data);
	else if (token->type == LOGICAL_EXPRESSION)
		ft_printf(": %s", type_to_string((intptr_t)token->data));
	else
		ft_printf(": %s", (char *)token->data);
}

void	ast_print(t_ntree *ast)
{
	ntree_print(ast, (t_unary_fun)print_data);
}

void	print_leaf(t_ntree *leaf)
{
	t_token *const	token = get_token(leaf);

	ft_printf("type : %s, ", type_to_string(token->type));
	ft_printf("data : %s\n", (char *)token->data);
}
