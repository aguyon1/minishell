/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_basics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:08:34 by bguillau          #+#    #+#             */
/*   Updated: 2023/10/13 17:29:10 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_envalue(char *key, char **envp)
{
	char	*key_comp;

	while (envp && *envp)
	{
		key_comp = get_key_2(*envp);
		if (!key_comp)
			return (NULL);
		if (!ft_strcmp(key, key_comp))
			return (xfree(key_comp), xstrdup(get_value(*envp)));
		xfree(key_comp);
		envp++;
	}
	return (xstrdup(""));
}

int	is_var_set(char *key, char **envp)
{
	char	*key_comp;

	if (!key || !envp)
		return (0);
	while (*envp)
	{
		key_comp = get_key_2(*envp);
		if (!key_comp)
			return (ALLOC_FAIL);
		if (!ft_strcmp(key, key_comp))
			return (xfree(key_comp), 1);
		xfree(key_comp);
		envp++;
	}
	return (0);
}

int	is_key_valid(char *key, char *line)
{
	const char	*bad_char = ",.:!?~*^%$#@[]{}+-/\\";

	if (ft_strlen(key) == 0 || (*key != 95 && !ft_isalpha(*key)))
		return (err_builtin("export", line, ERR_ID_EXPORT), 0);
	while (*key)
	{
		if (ft_strchr(bad_char, *key))
			if (!(*key == '+' && *(key + 1) == '\0'))
				return (err_builtin("export", line, ERR_ID_EXPORT), 0);
		key++;
	}
	return (1);
}
