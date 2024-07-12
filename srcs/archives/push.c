/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:19:00 by claprand          #+#    #+#             */
/*   Updated: 2024/07/12 16:15:27 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (*a == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
}

void	do_pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	do_pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}