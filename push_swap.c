/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:35 by bammar            #+#    #+#             */
/*   Updated: 2022/12/18 15:54:58 by bammar           ###   ########.fr       */
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


void printdq(t_dq *dq)
{
	t_dlist *node;

	node = dq->head;
	while (node)
	{
		printf("%d, ", node->content);
		node = node->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_ps		*ps;
	int			path;

	if (argc == 1)
		return (0);
	ps = ps_init(argc, argv);
	if (!ps)
		return (ft_putstr_fd("Error\nInvalid Arguments\n", 2), 1);
	radix(ps);
	while (ps->b->head)
	{
		path = change_path(ps->b, &ps->s->tail->content, ft_dqsize(ps->b));
		if (ps->b->head->content == ps->s->tail->content || (ps->s->tail->prev && ps->b->head->content == ps->s->tail->prev->content))
		{
			if (ps->b->head->content == ps->s->tail->content)
				ft_dqdel_last(ps->s);
			push_from(ps->b, ps->a);
			printf("pa\n");
			if (ps->s->tail && (ps->s->tail->prev && ps->a->head->content == ps->s->tail->prev->content) && ft_dqsize(ps->a) > 1)
			{
				rotate(ps->a);
				printf("ra\n");
			}
			else if (ps->s->tail && ps->s->tail->content == ps->a->tail->content)
			{
				rrotate(ps->a);
				printf("rra\n");
				ft_dqdel_last(ps->s);
			}
		}
		else if (path == 0 && ft_dqcontains(ps->b, ps->s->tail->content))
		{
			rotate(ps->b);
			printf("rb\n");
		}
		else if (ft_dqcontains(ps->b, ps->s->tail->content))
		{
			rrotate(ps->b);
			printf("rrb\n");
		}
	}
	if (argc == 2)
		sp_free(ps->argv);
	return (free(ps), 0);
}
