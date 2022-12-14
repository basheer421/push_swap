/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:44 by bammar            #+#    #+#             */
/*   Updated: 2022/12/14 16:51:40 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include "ft_deque/ft_dq.h"
#include "limits.h"
#include "stdio.h" // remove

typedef struct	s_ps
{
	t_dq	*a;
	t_dq	*b;
	t_dq	*s;
}	t_ps;

int		swap_top(t_dq *dq);
int		push_from(t_dq *src, t_dq *dst);
int		rotate(t_dq *dq);
int		rrotate(t_dq *dq);

t_ps	*ps_init(int argc, char **argv);
t_ps	*ps_new(void);
void	ps_destroy(t_ps *ps);
long	ft_atol(const char *str);
void	tab_sort(u_int64_t *t, int size);
int		ps_dqfill(t_dq *dq, u_int64_t *tab, int size);
void	ps_dqfree(t_dq	*dq);
int		ps_has_negative(t_dq *dq);

#endif