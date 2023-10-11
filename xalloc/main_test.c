/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:44:29 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/10 22:21:33 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocation.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>

static char	*xstrdup(const char *str)
{
	return (strcpy(xmalloc(strlen(str) + 1), str));
}

void	putstr(const char *str)
{
	write(1, str, strlen(str));
}

int	main(void)
{
	pid_t	pid;
	void	*buffer;

	buffer = xmalloc(1000);
	return (0);
}
