/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:35 by bammar            #+#    #+#             */
/*   Updated: 2022/12/21 19:44:15 by bammar           ###   ########.fr       */
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

int	is_empty(char **argv)
{
	int	i;

	if (!argv[1] || !*argv[1])
		return (1);
	i = 0;
	while (is_space(argv[1][i]))
		i++;
	if (!argv[1][i])
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc == 1 || (argc == 2 && is_empty(argv)))
		return (0);
	ps = ps_init(argc, argv);
	if (!ps)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (!is_sorted(ps->a))
	{
		if (ft_dqsize(ps->a) <= 5)
			small_sort(ps, ft_dqsize(ps->a));
		else
		{
			radix(ps);
			push_back(ps);
		}
	}
	ps_destroy(ps);
	return (0);
}
