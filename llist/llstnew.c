/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llstnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:17:01 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/13 17:22:31 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

t_llist	*llstnew(void *content)
{
	t_llist *const	new = xmalloc(sizeof(t_llist));

	*new = (t_llist){content, NULL, NULL};
	return (new);
}
