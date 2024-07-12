/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:54:35 by claprand          #+#    #+#             */
/*   Updated: 2024/07/12 16:08:14 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a->next != NULL)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort(t_stack **a, t_stack **b)
{
	int size;

	size = get_stack_size(*a);
	if (size == 1)
		return ;
	if (size <= 3)
		sort_tiny(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack *b;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
		exit_error(NULL, NULL);
	b = NULL;
	a = init_stack(ac, av);
	create_index(a);
	sort(&a, &b);

	t_stack *tmp;
	tmp = a;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp  = tmp->next;
	}
	
	freestack(&a);
	freestack(&b);
	return (0);
}
