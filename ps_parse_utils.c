/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:37:58 by bammar            #+#    #+#             */
/*   Updated: 2022/12/14 16:51:52 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_dqfill(t_dq *dq, u_int64_t *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_dqadd_last(dq, ftdlst_new(tab[i]));
		if (dq->tail == NULL)
			return (-1);
		i++;
	}
	return (0);
}

void	ps_dqfree(t_dq	*dq)
{
	if (!dq)
		return ;
	while (dq->head != NULL)
		ft_dqdel_first(dq);
}

int		ps_has_negative(t_dq *dq)
{
	t_dlist	*node;

	node = dq->head;
	if (node == NULL)
		return (-1);
	while (node != NULL)
	{
		if (node->content < 0)
			return (1);
		node = node->next;
	}
	return (0);
}
