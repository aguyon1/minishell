/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:32:40 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/13 13:17:29 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	err_msg(const char *str, const char *err)
{
	ft_dprintf(2, "minishell: %s: %s\n", str, err);
}

void	err_builtin(const char *builtin, const char *arg, const char *err)
{
	ft_dprintf(2, "minishell: %s: `%s': %s\n", builtin, arg, err);
}

void	print_err_ambiguous(const char *str)
{
	ft_dprintf(2, "minishell: %s: ambiguous redirect\n", str);
}

void	print_err_quotes(void)
{
	ft_dprintf(2, "minishell: quotes unclosed\n");
}
