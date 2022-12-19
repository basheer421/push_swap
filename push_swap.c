/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:35 by bammar            #+#    #+#             */
/*   Updated: 2022/12/19 19:59:02 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_dq *a)
{
	t_dlist	*node1;

	node1 = a->head;
	if (!node1)
		return (0);
	while (node1->next)
	{
		if (node1->content > node1->next->content)
			return (0);
		node1 = node1->next;
	}
	return (1);
}

static void	push2b(t_ps *ps, int size)
{
	int	i;

	i = size;
	while (i-- > 3)
	{
		push_from(ps->a, ps->b);
		ft_putstr_fd("pb\n", 1);
	}
}

static void	repush2b(t_ps *ps)
{
	while (ps->b->head)
	{
		while (ps->a->head->content < ps->b->head->content
			&& ps->b->head->content != ps->s->tail->content)
		{
			rotate(ps->a);
			ft_putstr_fd("ra\n", 1);
		}
		push_from(ps->b, ps->a);
		ft_putstr_fd("pa\n", 1);
		while (!is_sorted(ps->a))
		{
			rotate(ps->a);
			ft_putstr_fd("ra\n", 1);
		}
	}
}

void	small_sort(t_ps *ps, int size)
{
	push2b(ps, size);
	while (!is_sorted(ps->a))
	{
		if (ps->a->head->content > ps->a->head->next->content)
		{
			rotate(ps->a);
			ft_putstr_fd("ra\n", 1);
		}
		else
		{
			swap_top(ps->a);
			ft_putstr_fd("sa\n", 1);
		}
	}
	repush2b(ps);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc == 1)
		return (0);
	ps = ps_init(argc, argv);
	if (!ps)
		return (ft_putstr_fd("Error\nInvalid Arguments\n", 2), 1);
	if (!is_sorted(ps->a))
	{
		if (argc - 1 <= 5)
			small_sort(ps, argc - 1);
		else
		{
			radix(ps);
			push_back(ps);
		}
	}
	if (argc == 2)
		sp_free(ps->argv);
	free(ps);
	return (0);
}
