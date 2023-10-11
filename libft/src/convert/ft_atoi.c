/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:27:58 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/11 20:16:10 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*strfold(char *str, void *acc, void *f(void *, char *))
{
	if (*str == '\0')
		return (acc);
	return (strfold(str + 1, f(acc, str), f));
}

char	*strskip(const char *nptr, const char *skipable)
{
	while (ft_strchr(skipable, *nptr))
		nptr++;
	return ((char *)nptr);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	nptr += ft_strspn(nptr, " \f\n\r\t\v");
	if (*nptr == '-')
		sign *= -1;
	if (ft_strchr("-+", *nptr))
		nptr++;
	while (ft_isdigit(*nptr))
		res = res * 10 + *nptr++ - '0';
	return (res * sign);
}
