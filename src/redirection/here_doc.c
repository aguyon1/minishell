/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:19:21 by bguillau          #+#    #+#             */
/*   Updated: 2023/10/13 17:33:54 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	read_here_doc(char **data, const char *lim)
{
	char	*line;
	char	*lim_without_quote;

	lim_without_quote = remove_quote((char *)lim);
	if (lim_without_quote == NULL)
		return (xfree(*data), ERRALLOC);
	*data = xstrdup("");
	if (data == NULL)
		return (xfree(lim_without_quote), ERRALLOC);
	while (1)
	{
		line = readline(HD_PROMPT);
		if (g_last_signum == SIGINT)
			return (xfree(lim_without_quote), xfree(*data), ERRSIGINT);
		if (!line || !ft_strcmp(line, lim_without_quote))
			break ;
		*data = xstrjoin(*data, xstrjoin(line, xstrdup("\n")));
		if (*data == NULL)
			return (xfree(lim_without_quote), ERRALLOC);
	}
	return (xfree(line), xfree(lim_without_quote), SUCCESS);
}

int	launch_here_doc(int fd, const char *lim, t_minishell *minishell)
{
	char	*data;
	char	*temp;
	int		return_code;

	return_code = read_here_doc(&data, lim);
	if (return_code != SUCCESS)
		return (return_code);
	if (!is_str_enclosed_quote(lim))
	{
		temp = expand_dollar_here_doc(data, minishell->envp, minishell->status);
		xfree(data);
		if (temp == NULL)
			return (ERRALLOC);
		data = temp;
	}
	write(fd, data, ft_strlen(data));
	return (xfree(data), SUCCESS);
}

void	open_here_doc_child(const char *lim, int fd, t_minishell *minishell)
{
	set_here_doc_signals();
	minishell->status = launch_here_doc(fd, lim, minishell);
	xclose(fd);
	free_and_exit_child(minishell);
}

int	open_here_doc_parent(int fd, char *pathname)
{
	int	status;

	status = 0;
	signal(SIGINT, SIG_IGN);
	wait(&status);
	status = WEXITSTATUS(status);
	xclose(fd);
	if (status != 0)
		return (status - 256);
	fd = xopen_mode(pathname, O_RDONLY, 00644);
	if (fd < 0)
		return (perror("open here_doc in rd"), ERRFD);
	return (fd);
}

/*	create+open tmpfile in w, launch_hd to it. close n reopen in r	*/
int	open_here_doc(const char *lim, t_minishell *minishell)
{
	static int	nb = 0;
	char		*pathname;
	int			fd;

	pathname = ft_strjoin3(HD_START, ft_itoa(nb++), HD_END);
	if (pathname == NULL)
		return (ERRALLOC);
	fd = create_tmp_file(pathname, minishell);
	if (fd < -1)
		return (fd);
	if (fork() == 0)
		open_here_doc_child(lim, fd, minishell);
	else
		fd = open_here_doc_parent(fd, pathname);
	return (fd);
}
