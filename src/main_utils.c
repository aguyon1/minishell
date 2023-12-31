/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:19:49 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/13 17:25:31 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_parenthesis_closed(t_llist *token_list, char **operator_err)
{
	t_llist	*current;
	t_token	*current_token;
	int		n;

	n = 0;
	current = token_list;
	while (current != NULL && n >= 0)
	{
		current_token = current->content;
		if (current_token->type == opening_parenthesis)
			n += 1;
		else if (current_token->type == closing_parenthesis)
			n -= 1;
		current = current->next;
	}
	if (n > 0)
		*operator_err = "(";
	else if (n < 0)
		*operator_err = ")";
	else
		*operator_err = "";
	return (n);
}

t_state	manage_redirection(t_minishell *minishell)
{
	int	return_code;

	return_code = manage_here_doc(minishell->ast, minishell);
	if (return_code == EXIT)
		return (minishell->status = 1, EXIT);
	if (return_code == CONTINUE)
		return (minishell->status = 130, CONTINUE);
	manage_redir(minishell->ast, minishell->envp);
	return (OK);
}

void	token_list_cleanup(t_llist **token_list)
{
	llstclear(token_list, token_free);
}

t_state	interpret_command(const char *line, t_minishell *minishell)
{
	int		return_code;

	__attribute((cleanup(token_list_cleanup))) t_llist * token_list;
	token_list = tokenization(line);
	if (token_list == NULL)
		return (EXIT);
	if (!check_quotes(token_list))
		return (minishell->status = 2, print_err_quotes(), CONTINUE);
	return_code = expand_token_list(&token_list, minishell);
	if (return_code != OK)
		return (return_code);
	if (check_syntax(token_list) != 0)
		return (minishell->status = 2, CONTINUE);
	minishell->ast = create_complete_command(token_list);
	llstclear(&token_list, token_free);
	if (minishell->ast == NULL)
		return (EXIT);
	return_code = manage_redirection(minishell);
	if (return_code != OK)
		return (return_code);
	if (manage_pipeline(minishell, minishell->ast) != 0)
		return (EXIT);
	ast_close_unused_fds(minishell->ast);
	minishell->status = execute_ast(minishell);
	return (OK);
}

void	reader_loop(t_minishell *minishell)
{
	char	*line;

	g_last_signum = 0;
	set_prompt_signals();
	line = readline("\e[1;33mprompt 👉 \e[0m");
	if (g_last_signum != 0)
		minishell->status = g_last_signum + 128;
	if (line == NULL)
		return (ft_putendl_fd("exit", 2));
	else if (is_str_blank(line))
		return (xfree(line), reader_loop(minishell));
	add_history(line);
	if (interpret_command(line, minishell) == EXIT)
		return (minishell->status = 1, xfree(line), free_loop(minishell));
	return (xfree(line), free_loop(minishell), reader_loop(minishell));
}
