/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:43:43 by bguillau          #+#    #+#             */
/*   Updated: 2023/10/13 17:26:31 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_pwd(char **args)
{
	if (args[1] && args[1][0] == '-')
		if (args[1][1] == 'P' || args[1][1] == 'L')
			return (0);
	return (1);
}

static int	check_args(char **args)
{
	if (args[1] && args[1][0] == '-')
	{
		if (ft_strlen(args[1]) > 1 && ft_strcmp(args[1], "--"))
		{
			err_builtin("pwd", args[1], ERR_INVOPT);
			write(2, PWD_USAGE, ft_strlen(PWD_USAGE));
			return (0);
		}
	}
	return (1);
}

int	pwd(char **args)
{
	char	*str;

	if (!check_args(args))
		return (BUILTIN_ERR_CODE);
	str = NULL;
	str = getcwd(str, 0);
	if (!str)
		return (BUILTIN_ERR_CODE);
	ft_printf("%s\n", str);
	xfree(str);
	return (0);
}
