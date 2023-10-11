/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xsubstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:31:47 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/11 20:16:10 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static size_t	min(size_t x, size_t y)
{
	return (x ^ ((y ^ x) & -(x > y)));
}

char	*xsubstr(char const *s, unsigned int start, size_t len)
{
	return (xstrndup(s + min(start, ft_strlen(s)), len));
}
