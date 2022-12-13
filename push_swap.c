/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:35 by bammar            #+#    #+#             */
/*   Updated: 2022/12/13 19:15:43 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void printdq(t_dq *a)
// {
// 	while (a->head != NULL)
// 	{
// 		ft_putnbr_fd(a->head->content, 1);
// 		write(1, "\n", 1);
// 		ft_dqdel_first(a);
// 	}
// }

static int leftmost(int num)
{
	int	msb;

	if (num <= 0)
		return (0); // not implemented.
	msb = 65536;
	while ((msb & num) == 0)
		msb = msb >> 1;
	return (msb);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;
	int		num;

	if (argc == 1)
		return (0);
	ps = ps_init(argc, argv);
	if (!ps)
		return (ft_putstr_fd("Error\nInvalid Arguments\n", 2), 1);
	
	// while (ps->a->head) {
	// 	num = ps->a->head->content;
	// }
	
	(void)num;
	return (0);
}
