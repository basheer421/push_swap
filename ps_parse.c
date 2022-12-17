/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:13:54 by bammar            #+#    #+#             */
/*   Updated: 2022/12/17 18:04:56 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*ps_new(void)
{
	t_ps	*ps;

	ps = malloc(sizeof(t_ps));
	if (!ps)
		return (NULL);
	ps->a = ftdq_new();
	if (!ps->a)
		return (NULL);
	ps->b = ftdq_new();
	if (!ps->b)
		return (NULL);
	ps->s = ftdq_new();
	if (!ps->s)
		return (NULL);
	return (ps);
}

void	ps_destroy(t_ps *ps)
{
	ps_dqfree(ps->a);
	ps_dqfree(ps->b);
	ps_dqfree(ps->s);
	free(ps->a);
	free(ps->b);
	free(ps->s);
	free(ps);
}

static int	is_in(int item, int *lst, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (lst[i] == item)
			return (1);
		i++;
	}
	return (0);
}

static int	*get_nums(int argc, char **argv)
{
	int		*nums;
	long	num;
	int		i;

	nums = malloc(sizeof(int) * (argc + 1));
	if (!nums)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (((num == 0) && (ft_strncmp(argv[i], "0", 1) != 0)) || ((num == -1)
				&& (ft_strncmp(argv[i], "-1", 2) != 0)) || (num < INT_MIN)
			|| (num > INT_MAX) || (is_in(num, nums, i)))
			return (free(nums), NULL);
		nums[i++] = (int)num;
	}
	nums[i] = 0;
	return (nums);
}

void	indexify(t_ps *ps)
{
	t_dlist	*node;
	int		index;

	node = ps->a->head;
	while (node)
	{
		node->content = get_index(node->content, ps->s->head);
		node = node->next;
	}
	node = ps->s->head;
	index = 0;
	while (node)
	{
		node->content = index++;
		node = node->next;
	}
}

t_ps	*ps_init(int argc, char **argv)
{
	t_ps	*ps;
	int		*nums;
	int		count;

	ps = ps_new();
	if (!ps)
		return (NULL);
	ps->argv = argv + 1;
	if (argc == 2)
	{
		ps->argv = ft_split(argv[1], ' ');
		if (sp_numcount(ps->argv) < 2)
			return (sp_free(ps->argv), free(ps), NULL);
	}
	count = sp_numcount(ps->argv);
	nums = get_nums(count, ps->argv);
	if (!nums)
		return (NULL);
	if (ps_dqfill(ps->a, nums, count) == -1)
		return (free(nums), ps_destroy(ps), NULL);
	tab_sort(nums, count);
	if (ps_dqfill(ps->s, nums, count) == -1)
		return (free(nums), ps_destroy(ps), NULL);
	return (indexify(ps), free(nums), ps);
}
