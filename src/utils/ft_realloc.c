/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:06:17 by bguillau          #+#    #+#             */
/*   Updated: 2023/10/13 19:37:37 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <stddef.h>

void	*ft_realloc(void *ptr, size_t size)
{
	char	*new;

	if (!ptr)
		return (xmalloc(size));
	new = xmalloc(size);
	ft_memcpy(new, ptr, ft_strlen(ptr));
	xfree(ptr);
	return (new);
}
