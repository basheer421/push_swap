/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:35 by bammar            #+#    #+#             */
/*   Updated: 2022/12/14 19:51:20 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void printdq(t_dq *a)
// {
// 	while (a->head != NULL)
// 	{
// 		printf("%llu\n", a->head->content);
// 		ft_dqdel_first(a);
// 	}
// }

static u_int64_t leftmost(u_int64_t num)
{
	u_int64_t	msb;

	msb = 9223372036854775808ULL;
	while ((msb & num) == 0)
		msb = msb >> 1;
	return (msb);
}

int	dq_contains_bit(t_dq *dq, u_int64_t *item)
{
	t_dlist	*node;

	if (!item)
		return (0);
	node = dq->head;
	while (node)
	{
		if (node->content >= *item)
			return (1);
		node = node->next;
	}
	return (0);
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
	
	u_int64_t	left;
	int			i;
	int			y;

	left = leftmost(ps->s->tail->content); //of max
	// printf("%llu\n", left);
	y = 0;
	// while (y < 3)
	// {
		if (ps->a)
			while (left > 0)
			{
				i = 0;
				while (i < argc - 1 && dq_contains_bit(ps->a, &left))
				{
					if ((ps->a->head->content & left) != 0)
					{
						push_from(ps->a, ps->b);
						printf("pb\n");
					}
					else
					{
						rotate(ps->a);
						printf("ra\n");
					}
					i++;
				}
				left = left >> 1;
			}
		// else
		// 	while (left > 0)
		// 	{
		// 		i = 0;
		// 		while (i < argc - 1 && dq_contains_bit(ps->b, &left))
		// 		{
		// 			if ((ps->a->head->content & left) != 0)
		// 			{
		// 				push_from(ps->b, ps->a);
		// 				printf("pa\n");
		// 			}
		// 			else
		// 			{
		// 				rrotate(ps->b);
		// 				printf("rb\n");
		// 			}
		// 			i++;
		// 		}
		// 		left = left >> 1;
		// 	}
	// }
	// printdq(ps->a);
	(void)num;
	return (0);
}
