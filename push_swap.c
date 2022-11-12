/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:35 by bammar            #+#    #+#             */
/*   Updated: 2022/11/12 17:07:20 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void printdq(t_dq *a)
{
	while (a->head != NULL)
	{
		write(1, a->head->content, 1);
		write(1, "\n", 1);
		ft_dqdel_first(a, ps_del);
	}
}

// static void	dqfree(t_dq	*dq)
// {
// 	while (a->head != NULL)
// 		ft_dqdel_first(a, ps_del);
// }

int main(void)
{
	t_dq	*a;
	t_dq	*b;

	a = ftdq_new();
	b = ftdq_new();
	ft_dqadd_last(a, ftdlst_new("d"));
	ft_dqadd_first(a, ftdlst_new("c"));
	ft_dqadd_first(a, ftdlst_new("b"));
	ft_dqadd_first(a, ftdlst_new("a"));
	
	ft_dqadd_last(b, ftdlst_new("x"));
	ft_dqadd_first(b, ftdlst_new("y"));
	ft_dqadd_first(b, ftdlst_new("z"));
	// swap_top(a); // Working
	// push_from(b, a);
	rrotate(b);
	printdq(a);
	write(1, "--\n", 3);
	printdq(b);
	free(a);
	free(b);
	// (void) dqfree;
	return (0);
}