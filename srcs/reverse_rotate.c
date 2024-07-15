/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:23:22 by claprand          #+#    #+#             */
/*   Updated: 2024/07/15 11:17:56 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_reverse_rotate(t_stack **stack, int id)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = (*stack);
	(*stack) = tmp->next;
	tmp->next = NULL;
	if (id == STACK_A)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
