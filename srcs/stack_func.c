/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:28:04 by claprand          #+#    #+#             */
/*   Updated: 2024/07/12 15:27:07 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value, int index)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = index;
	new->nb_elem += 1;
	new->next = NULL;
	return (new);
}

void	stack_add_front(t_stack **a, t_stack *nb)
{
	nb->next = *a;
	*a = nb;
}

t_stack	*stack_last(t_stack *a)
{
	while (a && a->next != NULL)
		a = a->next;
	return (a);
}

t_stack	*stack_before_last(t_stack *a)
{
	while(a && a->next && a->next->next != NULL)
		a = a->next;
	return(a);
}

void	stack_add_back(t_stack **a, t_stack *nb)
{
	t_stack	*last;

	if (!nb)
		return ;
	if (!*a)
	{
		*a = nb;
		return ;
	}
	last = stack_last(*a);
	last->next = nb;
}