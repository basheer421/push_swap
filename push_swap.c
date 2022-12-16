/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:35 by bammar            #+#    #+#             */
/*   Updated: 2022/12/16 22:11:45 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	change_path(t_dq *dq, int *item, int n)
{
	t_dlist	*node;
	int		i;

	i = 0;
	node = dq->head;
	while (node && i++ < n / 2)
	{
		if (node->content == *item)
			return (0);
		node = node->next;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	t_ps		*ps;
	int			path;

	if (argc == 1)
		return (0);
	ps = NULL;
	ps = ps_init(argc, argv);
	if (!ps)
		return (ft_putstr_fd("Error\nInvalid Arguments\n", 2), 1);
	radix(ps);
	while (ps->b->head)
	{
		path = change_path(ps->b, &ps->s->tail->content, ft_dqsize(ps->b));
		if (ps->b->head->content == ps->s->tail->content)
		{
			push_from(ps->b, ps->a);
			printf("pa\n");
			ft_dqdel_last(ps->s);
		}
		else
		{
			if (path == 0)
			{
				rotate(ps->b);
				printf("rb\n");
			}
			else
			{
				rrotate(ps->b);
				printf("rrb\n");
			}
		}
	}
	return (0);
}
