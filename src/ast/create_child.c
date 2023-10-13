/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:08:06 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/13 19:40:00 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_llist	*create_child_range(t_llist	*begin, t_llist	*end, \
t_ntree *(*create)(t_llist *, t_llist *))
{
	t_ntree *const	subtree = create(begin, end);

	return (llstnew(subtree));
}

t_llist	*create_child(t_llist *llist, t_ntree *(create)(t_llist *))
{
	t_ntree *const	subtree = create(llist);

	return (llstnew(subtree));
}
