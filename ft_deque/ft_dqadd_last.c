/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dqadd_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:53:37 by bammar            #+#    #+#             */
/*   Updated: 2022/11/07 23:01:00 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dq.h"

void	ft_dqadd_last(t_dq *lst, t_dlist *new)
{
	if (!lst)
		return ;
	if (!lst->tail)
	{
		lst->head = new;
		lst->tail = new;
		return ;
	}
	lst->tail->next = new;
	new->prev = lst->tail;
	return ;
}
