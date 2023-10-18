/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:06:17 by bguillau          #+#    #+#             */
/*   Updated: 2023/10/16 14:58:31 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <stddef.h>

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char	*new;

	if (!ptr)
		return (malloc(new_size));
	new = malloc(new_size);
	if (new == NULL)
		return (free(ptr), NULL);
	ft_memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}

void	*xrealloc(void *ptr, size_t old_size, size_t new_size)
{
	char	*new;

	if (!ptr)
		return (xmalloc(new_size));
	new = xmalloc(new_size);
	ft_memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}
