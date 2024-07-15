/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:19:14 by claprand          #+#    #+#             */
/*   Updated: 2024/07/15 11:16:05 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate(t_stack **stack, int id)
{
	t_stack	*tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = NULL;
	stack_last(*stack)->next = tmp;
	if (id == STACK_A)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}
