/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:08:04 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/11 20:16:10 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_itoa_aux(char *buffer, int n)
{
	if (n <= -10)
		buffer = ft_itoa_aux(buffer, n / 10);
	return (*buffer++ = (-(n % 10)) + '0', buffer);
}

char	*ft_itoa(int n)
{
	char	buffer[12];

	ft_bzero(buffer, 12);
	if (n < 0)
		return (buffer[0] = 45, ft_itoa_aux(buffer + 1, n), ft_strdup(buffer));
	return (ft_itoa_aux(buffer, -n), ft_strdup(buffer));
}
