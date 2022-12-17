/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:35 by bammar            #+#    #+#             */
/*   Updated: 2022/12/17 19:04:29 by bammar           ###   ########.fr       */
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
	int			temp;
	int			pend_rev;

	if (argc == 1)
		return (0);
	ps = ps_init(argc, argv);
	if (!ps)
		return (ft_putstr_fd("Error\nInvalid Arguments\n", 2), 1);
	radix(ps);
	temp = -1;
	pend_rev = 0;
	while (ps->b->head)
	{
		path = change_path(ps->b, &ps->s->tail->content, ft_dqsize(ps->b));
		if (ps->b->head->content == ps->s->tail->content || (ps->s->tail->prev &&  ps->b->head->content == ps->s->tail->prev->content))
		{
			if (ps->s->tail->prev && ps->b->head->content == ps->s->tail->prev->content && pend_rev == 0)
			{
				temp = ps->s->tail->content;
				ft_dqdel_last(ps->s);
				ft_dqdel_last(ps->s);
				ft_dqadd_last(ps->s, ftdlst_new(temp));
				push_from(ps->b, ps->a);
				printf("pa\n");
				rotate(ps->a);
				printf("ra\n");
				pend_rev++;
			}
			else
			{
				push_from(ps->b, ps->a);
				printf("pa\n");
				printf("num: %d\n", ps->b->head->content);
				ft_dqdel_last(ps->s);
				if (pend_rev == 1)
				{
					rrotate(ps->a);
					printf("rra\n");
					pend_rev = 0;
				}
			}
		}
		else if (path == 0)
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
	if (argc == 2)
		sp_free(ps->argv);
	return (free(ps), 0);
}
