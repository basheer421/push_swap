/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dqdel_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:01:22 by bammar            #+#    #+#             */
/*   Updated: 2022/11/12 16:07:00 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dq.h"

void	ft_dqdel_last(t_dq *lst, void (*del)(void *))
{
	t_dlist	*temp;

	if (!lst || !lst->tail)
		return ;
	temp = lst->tail;
	lst->tail = lst->tail->prev;
	if (lst->tail)
		lst->tail->next = NULL;
	else
		lst->head = NULL;
	del((void *)temp->content);
	free((void *)temp);
}
