/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:19:06 by claprand          #+#    #+#             */
/*   Updated: 2024/07/15 11:16:16 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_swap(t_stack **stack, int id)
{
	int		value;

	value = (*stack)->next->value;
	(*stack)->next->value = (*stack)->value;
	(*stack)->value = value;
	if (id == STACK_A)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}
