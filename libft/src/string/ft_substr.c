/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:43:43 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/11 20:16:10 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	const size_t	len_s = ft_strlen(s);

// 	if (len_s < start)
// 		return (ft_strdup(""));
// 	if (start + len > len_s)
// 		return (ft_strdup(s + start));
// 	return (ft_strndup(s + start, len));
// }

static size_t	min(size_t x, size_t y)
{
	return (x ^ ((y ^ x) & -(x > y)));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	return (ft_strndup(s + min(start, ft_strlen(s)), len));
}
