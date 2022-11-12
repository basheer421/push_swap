/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dqdel_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:01:37 by bammar            #+#    #+#             */
/*   Updated: 2022/11/12 16:09:02 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dq.h"

void	ft_dqdel_first(t_dq *lst, void (*del)(void *))
{
	t_dlist	*temp;

	if (!lst || !lst->head)
		return ;
	temp = lst->head;
	lst->head = lst->head->next;
	if (lst->head)
		lst->head->prev = NULL;
	else
		lst->tail = NULL;
	del((void *)temp->content);
	free((void *)temp);
}
