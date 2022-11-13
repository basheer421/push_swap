/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:37:58 by bammar            #+#    #+#             */
/*   Updated: 2022/11/13 14:26:37 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_dqfill(t_dq *dq, int *tab, int size)
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
