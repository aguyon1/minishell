/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:40:26 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/13 19:41:19 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	create_tmp_file(char *pathname, t_minishell *minishell)
{
	t_llist	*new_node;
	int		fd;

	fd = xopen_mode(pathname, O_TRUNC | O_WRONLY | O_CREAT, 00644);
	if (fd < 0)
		return (perror("open here_doc in w"), BAD_FD);
	new_node = llstnew(pathname);
	llstadd_back(&minishell->here_doc_files, new_node);
	return (fd);
}

char	*get_next(char *str)
{
	if (str[0] == '$')
	{
		str++;
		if (str[0] == '?')
			return (str + 1);
		else
			while (*str != '\0' && (ft_isalnum(*str) || *str == '_'))
				str++;
	}
	else
		while (*str && *str != '$')
			str++;
	return (str);
}

char	*expand_dollar_here_doc(char *str, char **envp, int status)
{
	char	*res;
	char	*next;
	char	*temp;

	res = xstrdup("");
	while (*str)
	{
		next = get_next(str);
		if (*str == '$')
			temp = my_expand(str, envp, status);
		else
			temp = ft_substr(str, 0, next - str);
		if (temp == NULL)
			return (NULL);
		res = strjoin(res, temp);
		xfree(temp);
		if (res == NULL)
			return (NULL);
		str = next;
	}
	return (res);
}
