/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dq.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:12:06 by bammar            #+#    #+#             */
/*   Updated: 2022/11/12 20:45:09 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DQ_H
# define FT_DQ_H

#include "../libft/libft.h"

typedef struct s_dlist
{
	int				content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}				t_dlist;

t_dlist	*ftdlst_new(int content);

typedef struct s_dq
{
	t_dlist	*head;
	t_dlist	*tail;
}					t_dq;

t_dq	*ftdq_new(void);
void	ft_dqadd_first(t_dq *lst, t_dlist *new);
void	ft_dqadd_last(t_dq *lst, t_dlist *new);
void	ft_dqdel_first(t_dq *lst);
void	ft_dqdel_last(t_dq *lst);

#endif