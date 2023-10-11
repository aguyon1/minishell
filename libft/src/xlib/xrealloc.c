/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xrealloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 01:54:13 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/11 20:52:26 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*xrealloc(void *ptr, size_t original_size, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (xmalloc(size));
	if (size == 0)
		return (xfree(ptr), NULL);
	if (original_size <= size)
		return (ptr);
	new_ptr = ft_memcpy(xmalloc(size), ptr, original_size);
	return (xfree(ptr), new_ptr);
}
