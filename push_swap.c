/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:35 by bammar            #+#    #+#             */
/*   Updated: 2022/11/12 16:22:28 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
	t_dq	*x;

	x = ftdq_new();
	ft_dqadd_first(x, ftdlst_new("1"));
	ft_dqadd_first(x, ftdlst_new("2"));
	ft_dqadd_first(x, ftdlst_new("3"));
	ft_dqadd_first(x, ftdlst_new("9"));
	// sa(x);
	while (x->head != NULL)
	{
		write(1, x->head->content, 1);
		write(1, "\n", 1);
		ft_dqdel_first(x, ps_del);
		
	}
	free(x);
	return 0;
}
