/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xsplit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:48:16 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/11 20:16:10 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static size_t	get_nb_words(const char *str, const char *sep)
{
	size_t	nb_words;
	size_t	len_word;

	nb_words = 0;
	str += ft_strspn(str, sep);
	while (*str)
	{
		len_word = ft_strcspn(str, sep);
		str += len_word + ft_strspn(str + len_word, sep);
		nb_words++;
	}
	return (nb_words);
}

char	**xsplit(const char *str, const char *sep)
{
	char **const	strs = xmalloc(sizeof(char *) * get_nb_words(str, sep));
	size_t			len_word;
	register size_t	i;

	str += ft_strspn(str, sep);
	i = 0;
	while (*str)
	{
		len_word = ft_strcspn(str, sep);
		strs[i++] = xstrndup(str, len_word);
		str += len_word + ft_strspn(str + len_word, sep);
	}
	strs[i] = NULL;
	return (strs);
}
