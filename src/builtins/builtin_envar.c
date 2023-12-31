/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_envar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:12:42 by bguillau          #+#    #+#             */
/*   Updated: 2023/10/13 17:31:25 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	add_envar(char *key, char *value, char ***envp)
{
	char	*env_line;

	if (ft_strchr(key, '+'))
		key[ft_strlen(key) - 1] = '\0';
	env_line = xstrjoin(key, "=");
	env_line = strjoin(env_line, value);
	if (!env_line)
		return (ALLOC_FAIL);
	*envp = charmatrix_add_one(*envp, env_line);
	if (!*envp)
		return (ALLOC_FAIL);
	return (1);
}

int	supp_envar(char *key, char ***envp)
{
	*envp = charmatrix_del_one(*envp, key);
	if (!*envp)
		return (ALLOC_FAIL);
	return (1);
}

int	mod_envar(char *key, char *new_value, char **envp)
{
	char	*env_line;
	char	*key_comp;

	env_line = xstrjoin(key, "=");
	env_line = strjoin(env_line, new_value);
	if (!env_line)
		return (ALLOC_FAIL);
	while (envp && *envp)
	{
		key_comp = get_key_2(*envp);
		if (!key_comp)
			return (ALLOC_FAIL);
		if (!ft_strcmp(key, key_comp))
		{
			xfree(*envp);
			*envp = env_line;
			return (xfree(key_comp), 1);
		}
		xfree(key_comp);
		envp++;
	}
	return (0);
}

/*	for export += when var is set	*/
int	concat_envar(char *key, char *new_value, char **envp)
{
	char	*key_comp;

	key[ft_strlen(key) - 1] = '\0';
	while (envp && *envp)
	{
		key_comp = get_key_2(*envp);
		if (!key_comp)
			return (ALLOC_FAIL);
		if (!ft_strcmp(key, key_comp))
		{
			*envp = strjoin(*envp, new_value);
			if (!*envp)
				return (xfree(key_comp), ALLOC_FAIL);
			return (xfree(key_comp), 1);
		}
		xfree(key_comp);
		envp++;
	}
	return (0);
}
