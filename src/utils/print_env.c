/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:35:03 by bguillau          #+#    #+#             */
/*   Updated: 2023/10/13 13:17:16 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_env(char **envp, char *prefix)
{
	while (envp && *envp)
	{
		if (prefix)
			ft_printf("%s", prefix);
		ft_printf("%s\n", *envp);
		envp++;
	}
}

void	print_envar_bad(char *var, char **envp)
{
	while (envp && *envp)
	{
		if (!ft_strncmp(*envp, var, ft_strlen(var)))
			return ((void)ft_printf("%s\n", *envp));
		envp++;
	}
}
