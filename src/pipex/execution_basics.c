/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_basics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:46:45 by bguillau          #+#    #+#             */
/*   Updated: 2023/10/13 17:21:38 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <dirent.h>

int	analyze_status(t_info *info)
{
	int				status;
	t_cmd			*last_cmd;
	unsigned char	signum;

	last_cmd = cmd_last(info->cmd_start);
	status = info->exit_code;
	if (last_cmd->exist)
		return (127);
	if (last_cmd->is_exec)
		return (126);
	if (last_cmd->fd_in == REDIR_PB || last_cmd->fd_out == REDIR_PB)
		return (1);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
	{
		signum = WTERMSIG(status);
		print_signal(signum);
		return (signum + 128);
	}
	return (status);
}

void	wait_cmds(t_info *info)
{
	int		child_status;
	pid_t	ret;

	ret = 0;
	while (ret != -1)
	{
		ret = waitpid(-1, &child_status, 0);
		if (ret == info->last_pid)
			info->exit_code = child_status;
	}
}

void	check_cmd_access(t_info *info, t_minishell *minishell)
{
	void	*tmp_dir_ptr;

	if (access(info->cmds->fullname, F_OK) || \
		!ft_strcmp(info->cmds->name, ".."))
	{
		if (!ft_strchr(info->cmds->name, '/'))
			err_msg(info->cmds->name, ERR_CNF);
		else
			err_msg(info->cmds->name, ERR_NSFD);
		return (minishell->status = 127, free_and_exit_child(minishell));
	}
	tmp_dir_ptr = opendir(info->cmds->fullname);
	if (tmp_dir_ptr)
	{
		closedir(tmp_dir_ptr);
		err_msg(info->cmds->name, ERR_IAD);
		return (minishell->status = 126, free_and_exit_child(minishell));
	}
	if (access(info->cmds->fullname, X_OK))
	{
		err_msg(info->cmds->name, ERR_PERMDEN);
		return (minishell->status = 126, free_and_exit_child(minishell));
	}
}

void	close_cmd_redirfiles(t_cmd *cmd)
{
	if (cmd->fd_in > 2)
		xclose(cmd->fd_in);
	if (cmd->fd_out > 2)
		xclose(cmd->fd_out);
}

void	execute(char **cmd_args, t_info *info, t_minishell *minishell)
{
	if (info->cmds->fd_in < 0 || info->cmds->fd_out < 0)
		return (minishell->status = 1, free_and_exit_child(minishell));
	if (!cmd_args)
		return (minishell->status = 0, free_and_exit_child(minishell));
	if (is_a_builtin(cmd_args, info->cmds->name))
		return (minishell->status = exec_builtin(info->cmds->name, cmd_args, \
			minishell), free_and_exit_child(minishell));
	check_cmd_access(info, minishell);
	execve(info->cmds->fullname, cmd_args, minishell->envp);
	perror(ERR_EXECVE);
	if (info->cmds->fd_in > NO_REDIR)
		xclose(info->cmds->fd_in);
	if (info->cmds->fd_out > NO_REDIR)
		xclose(info->cmds->fd_out);
	return (minishell->status = 1, free_and_exit_child(minishell));
}
