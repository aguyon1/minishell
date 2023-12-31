/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:05:23 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/13 17:23:47 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_info	*get_pipex_info(t_minishell *minishell, t_ntree *pipeline_node)
{
	t_info *const	pipex_info = xmalloc(sizeof(t_info));
	const size_t	nb_cmd = llstsize(pipeline_node->children);
	t_llist			*current;
	t_cmd			*new_cmd;
	size_t			i;

	if (pipex_info == NULL)
		return (NULL);
	pipex_info->exit_code = 0;
	pipex_info->last_pid = 0;
	pipex_info->cmds = NULL;
	current = pipeline_node->children;
	i = 0;
	while (i < nb_cmd)
	{
		new_cmd = cmd_new(current->content, i, minishell->envp);
		if (new_cmd == NULL)
			return (cmd_clear(&(pipex_info->cmds)), free(pipex_info), NULL);
		cmd_add_back(&(pipex_info->cmds), new_cmd);
		current = current->next;
		i++;
	}
	pipex_info->cmd_start = pipex_info->cmds;
	return (pipex_info);
}
