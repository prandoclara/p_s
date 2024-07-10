/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:19:06 by claprand          #+#    #+#             */
/*   Updated: 2024/07/10 15:42:39 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *a)
{
	int	tmp;

	if (!check_lst_len(a, 2))
		return ;
	if (a == NULL || a->next == NULL)
		return ;
	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
}

void	do_sa(t_stack **a)
{
	swap(*a);
	ft_putstr_fd("sa\n", 1);
}

void	do_sb(t_stack **b)
{
	swap(*b);
	ft_putstr_fd("sb\n", 1);
}

void	do_ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
	ft_putstr_fd("ss\n", 1);
}