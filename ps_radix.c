/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:19:56 by bammar            #+#    #+#             */
/*   Updated: 2022/12/17 18:09:21 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dq	*dq_copy(t_dq *dq)
{
	t_dq	*new_dq;
	t_dlist	*node;
	t_dlist	*temp;

	new_dq = ftdq_new();
	if (!new_dq)
		return (NULL);
	node = dq->head;
	while (node)
	{
		temp = ftdlst_new(node->content);
		if (!temp)
			return (NULL);
		ft_dqadd_last(new_dq, temp);
		node = node->next;
	}
	return (new_dq);
}

int	get_groupsize(int size)
{
	if (size <= 3)
		return (2);
	if (size <= 12)
		return (3);
	if (size <= 50)
		return (4);
	if (size <= 100)
		return (10);
	if (size <= 250)
		return (15);
	if (size <= 510)
		return (22);
	return (size * (0.05));
}

int	get_group(t_dq *sorted_dq, int num, int size)
{
	t_dlist	*node;
	int		i;
	int		groupcount;
	int		group_size;

	node = sorted_dq->head;
	i = 0;
	groupcount = 0;
	group_size = get_groupsize(size);
	while (node)
	{
		if (i == group_size)
		{
			groupcount++;
			i = 0;
		}
		if (node->content == num)
			return (groupcount);
		i++;
		node = node->next;
	}
	return (-1);
}

void	remove_from_stack(t_dq *dq, int item)
{
	t_dlist	*node;
	t_dlist	*temp;

	node = dq->head;
	while (node)
	{
		if (node->next && node->next->content == item)
		{
			temp = node->next;
			node->next = node->next->next;
			free(temp);
			return ;
		}
		node = node->next;
	}
}

void	radix(t_ps *ps)
{
	int		current_group;
	int		group;
	int		size;
	t_dq	*temp_dq;

	current_group = 0;
	size = ft_dqsize(ps->a);
	temp_dq = dq_copy(ps->s);
	while (ps->a->head)
	{
		group = get_group(temp_dq, ps->a->head->content, size);
		if (group == current_group)
		{
			push_from(ps->a, ps->b);
			ft_putendl_fd("pb", 1);
			remove_from_stack(temp_dq, ps->b->head->content);
		}
		else if (group == -1)
			current_group++;
		else
		{
			rotate(ps->a);
			ft_putendl_fd("ra", 1);
		}
	}
}
