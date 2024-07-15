/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:19:00 by claprand          #+#    #+#             */
/*   Updated: 2024/07/15 11:15:40 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push(t_stack **destination, t_stack **source, int id)
{
	t_stack	*tmp;

	tmp = (*source)->next;
	(*source)->next = (*destination);
	(*destination) = (*source);
	(*source) = tmp;
	if (id == STACK_A)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
