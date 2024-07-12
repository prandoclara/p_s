/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:23:22 by claprand          #+#    #+#             */
/*   Updated: 2024/07/12 16:14:58 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **a)
{
	t_stack *tmp;
	t_stack *last;
	t_stack *before_last;

	last = stack_last(*a);
	before_last = stack_before_last(*a);
	tmp = *a;
	*a = last;
	(*a)->next = tmp;
	before_last->next = NULL;
}

void	do_rra(t_stack **a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	do_rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	do_rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}