/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:44 by bammar            #+#    #+#             */
/*   Updated: 2022/11/12 16:29:06 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque/ft_dq.h"

void	ps_del(void *content);
int		swap_top(t_dq *dq);
int		push_from(t_dq *src, t_dq *dst);
int		rotate(t_dq *dq);
int		rrotate(t_dq *dq);
