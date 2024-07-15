/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:19:06 by claprand          #+#    #+#             */
/*   Updated: 2024/07/15 10:34:26 by claprand         ###   ########.fr       */
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
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}
