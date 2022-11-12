/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:35 by bammar            #+#    #+#             */
/*   Updated: 2022/11/12 22:39:04 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void printdq(t_dq *a)
// {
// 	while (a->head != NULL)
// 	{
// 		ft_putnbr_fd(a->head->content, 1);
// 		write(1, "\n", 1);
// 		ft_dqdel_first(a, ps_del);
// 	}
// }

// static void	dqfree(t_dq	*dq)
// {
// 	if (!dq)
// 		return ;
// 	while (a->head != NULL)
// 		ft_dqdel_first(a, ps_del);
// }

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc == 1)
		return (0);
	ps = ps_init(argc, argv);
	if (!ps)
		return (ft_putstr_fd("Error\nInvalid Arguments\n", 2), 1);
	ps_destroy(ps);
	return (0);
}
