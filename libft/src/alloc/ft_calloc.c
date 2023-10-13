/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:42:58 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/11 20:15:02 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	const size_t	total = nmemb * size;
	void			*res;

	if (total != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	res = malloc(total);
	if (res != NULL)
		ft_bzero(res, total);
	return (res);
}
