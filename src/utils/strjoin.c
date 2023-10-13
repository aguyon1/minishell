/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:00:17 by bguillau          #+#    #+#             */
/*   Updated: 2023/10/13 19:37:53 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include "../../inc/minishell.h"

/*	join 2 strings, free s1	*/
char	*strjoin(const char *s1, const char *s2)
{
	char	*ret;

	if (!s1 || !s2)
		return (xfree((void *)s1), NULL);
	ret = xstrjoin(s1, s2);
	xfree((void *)s1);
	return (ret);
}

/*	join 2 strings, free s1 + s2	*/
char	*strjoin2(const char *s1, const char *s2)
{
	char	*ret;

	if (!s1 || !s2)
		return (xfree((void *)s1), xfree((void *)s2), NULL);
	ret = xstrjoin(s1, s2);
	xfree((void *)s1);
	xfree((void *)s2);
	return (ret);
}

/*	join 3 strings, free s2 only	*/
char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*tmp;
	char	*ret;

	if (!s1 || !s2 || !s3)
		return (xfree((void *)s2), NULL);
	tmp = xstrjoin(s1, s2);
	ret = xstrjoin(tmp, s3);
	xfree((void *)s2);
	return (xfree((void *)tmp), ret);
}

/*	join 3 strings, free third only	*/
char	*strjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*tmp;
	char	*ret;

	if (!s1 || !s2 || !s3)
		return (xfree((void *)s3), NULL);
	tmp = xstrjoin(s1, s2);
	ret = xstrjoin(tmp, s3);
	xfree((void *)s3);
	return (xfree((void *)tmp), ret);
}

char	*str_one_char_join(char *str, char c)
{
	int	str_len;

	if (!str)
	{
		str_len = 0;
		str = xmalloc(2 * sizeof(char));
	}
	else
	{
		str_len = ft_strlen(str);
		str = ft_realloc(str, (str_len + 1 + 1) * sizeof(char));
	}
	str[str_len + 1] = '\0';
	str[str_len] = c;
	return (str);
}
