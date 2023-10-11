/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:06:19 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/11 20:47:07 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	register size_t			i;
	const unsigned char		*char_s1 = (const unsigned char *)s1;
	const unsigned char		*char_s2 = (const unsigned char *)s2;

	i = 0;
	while (char_s1[i] && char_s2[i] && i < n)
	{
		if (char_s1[i] != char_s2[i])
			break ;
		i++;
	}
	return (char_s1[i] - char_s2[i]);
}
