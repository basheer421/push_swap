/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mvswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:09:26 by bammar            #+#    #+#             */
/*   Updated: 2022/11/12 16:18:08 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_dq *dq)
{
	t_dlist	*first_top;
	t_dlist	*new_top;

	first_top = ftdlst_new(dq->head->content);
	if (!first_top)
		return (-1);
	ft_dqdel_first(dq, ps_del);
	new_top = ftdlst_new(dq->head->content);
	if (!new_top)
		return (-1);
	ft_dqdel_first(dq, ps_del);	
	ft_dqadd_first(dq, first_top);
	ft_dqadd_first(dq, new_top);
	return (0);
}