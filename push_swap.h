/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:44 by bammar            #+#    #+#             */
/*   Updated: 2022/12/16 21:34:18 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_deque/ft_dq.h"
# include "limits.h"
# include "stdio.h" // remove

typedef struct s_ps
{
	t_dq	*a;
	t_dq	*b;
	t_dq	*s;
	int		pending_ra;
	int		pending_rb;
	int		pending_rra;
	int		pending_rrb;
}			t_ps;

int			swap_top(t_dq *dq);
int			push_from(t_dq *src, t_dq *dst);
int			rotate(t_dq *dq);
int			rrotate(t_dq *dq);

int			get_index(int num, t_dlist *lst);
t_ps		*ps_init(int argc, char **argv);
t_ps		*ps_new(void);
void		ps_destroy(t_ps *ps);
long		ft_atol(const char *str);
void		tab_sort(int *t, int size);
int			ps_dqfill(t_dq *dq, int *tab, int size);
void		ps_dqfree(t_dq *dq);
int			ps_has_negative(t_dq *dq);
t_dq		*dq_copy(t_dq *dq);
int			get_groupsize(int size);
int			get_group(t_dq *sorted_dq, int num, int size);
void		remove_from_stack(t_dq *dq, int item);
void		radix(t_ps *ps);

#endif