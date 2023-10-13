/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_get_cmd_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:43:42 by bguillau          #+#    #+#             */
/*   Updated: 2023/10/13 17:32:04 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**get_path(char **envp)
{
	char	**no_path;

	while (envp && *envp)
	{
		if (!ft_strncmp("PATH=", *envp, 5))
			return (xsplit(get_value(*envp), ":"));
		envp++;
	}
	no_path = xmalloc(2 * sizeof(char *));
	no_path[0] = xstrdup("");
	no_path[1] = NULL;
	return (no_path);
}

char	*get_full_cmd_name(char *cmd_name, char **envp)
{
	int		i;
	char	**path;
	char	*tmp_name;

	if (*cmd_name == '\0')
		return (xstrdup(""));
	if (ft_strchr(cmd_name, '/'))
		return (xstrdup(cmd_name));
	path = get_path(envp);
	if (!path)
		return (NULL);
	if (!ft_strlen(path[0]) && !path[1])
		return (xfree(path[0]), xfree(path), xstrdup(""));
	i = -1;
	while (path[++i])
	{
		tmp_name = xstrjoin(path[i], "/");
		tmp_name = strjoin(tmp_name, cmd_name);
		if (!tmp_name)
			return (free_char_matrix(path), NULL);
		if (!access(tmp_name, F_OK))
			return (free_char_matrix(path), tmp_name);
		xfree(tmp_name);
	}
	return (free_char_matrix(path), xstrdup(""));
}
