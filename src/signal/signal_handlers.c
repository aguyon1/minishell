/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:44:01 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/13 17:22:03 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	handle_prompt_signals(int signum)
{
	if (signum == SIGINT)
	{
		g_last_signum = signum;
		ft_putendl_fd("", 2);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	handle_here_doc_signals(int signum)
{
	if (signum == SIGINT)
	{
		g_last_signum = signum;
		ft_putendl_fd("", 2);
		xclose(0);
	}
}
