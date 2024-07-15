/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:28:49 by claprand          #+#    #+#             */
/*   Updated: 2024/07/15 10:33:50 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	sort_tiny(t_stack **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		do_rotate(stack, STACK_A);
	else if ((*stack)->next->index == highest)
		do_reverse_rotate(stack, STACK_A);
	if ((*stack)->index > (*stack)->next->index)
		do_swap(stack, STACK_A);
}

void	sort_four(t_stack **a, t_stack **b)
{
	while ((*a)->index != 3)
		do_rotate(a, STACK_A);
	do_push(b, a, STACK_B);
	sort_tiny(a);
	do_push(a, b, STACK_A);
	do_rotate(a, STACK_A);
}

void	sort_five(t_stack **a, t_stack **b)
{
	if (stack_last(*a)->index == 3 || (*a)->next->next->next->index == 3)
	{
		while ((*a)->index != 3)
			do_reverse_rotate(a, STACK_A);
		do_push(b, a, STACK_B);
	}
	else
	{
		while ((*a)->index != 3)
			do_rotate(a, STACK_A);
		do_push(b, a, STACK_B);
	}
	if (stack_last(*a)->index == 4)
		do_reverse_rotate(a, STACK_A);
	while ((*a)->index != 4)
		do_rotate(a, STACK_A);
	do_push(b, a, STACK_B);
	sort_tiny(a);
	do_push(a, b, STACK_A);
	do_push(a, b, STACK_A);
	do_rotate(a, STACK_A);
	do_rotate(a, STACK_A);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	j = 0;
	size = get_stack_size(*a);
	max_bits = get_maxbits(size);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				do_rotate(a, STACK_A);
			else
				do_push(b, a, STACK_B);
			j++;
		}
		while (get_stack_size(*b) != 0)
			do_push(a, b, STACK_A);
		i++;
	}
}
