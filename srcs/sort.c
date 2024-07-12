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
		do_ra(stack);
	else if ((*stack)->next->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}


void	sort_four(t_stack **a, t_stack **b)
{
	while ((*a)->index != 3)
		do_ra(a);
	do_pb(a, b);
	sort_tiny(a);
	do_pa(b, a);
	do_ra(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	if (stack_last(*a)->index == 3 || (*a)->next->next->next->index == 3)
	{
		while ((*a)->index != 3)
			do_ra(a);
		do_pb(a, b);
	}
	else
	{
		while ((*a)->index != 3)
			do_rra(a);
		do_pa(b, a);
	}
	if (stack_last(*a)->index == 4)
		do_rra(a);
	while ((*a)->index != 4)
		do_ra(a);
	do_pb(a, b);
	sort_tiny(a);
	do_pa(b, a);
	do_pa(b, a);
	do_ra(a);
	do_ra(a);
}


void	radix_sort(t_stack **a, t_stack **b)
{
	int size;
	int max_bits;
	int i;
	int j;

	i = 0;
	size = get_stack_size(*a);
	max_bits = get_maxbits(size);
	while (i < max_bits)
	{
		j = 0;
		while (++j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				do_ra(a);
			else
				do_pb(a, b);
		}
		while (get_stack_size(*b) != 0)
			do_pa(b, a);
		i++;
	}
}