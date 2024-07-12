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
		ps_rotate_up(stack, STACK_A);
	else if ((*stack)->next->index == highest)
		ps_rotate_down(stack, STACK_A);
	if ((*stack)->index > (*stack)->next->index)
		ps_swap(*stack, STACK_A);
}


void	sort_four(t_stack **a, t_stack **b)
{
	while ((*a)->index != 3)
		ps_rotate_up(a, STACK_A);
	ps_push(b, a, STACK_B);
	sort_tiny(a);
	ps_push(a, b, STACK_A);
	ps_rotate_up(a, STACK_A);
}

void	sort_five(t_stack **a, t_stack **b)
{
	if (stack_last(*a)->index == 3 || (*a)->next->next->next->index == 3)
	{
		while ((*a)->index != 3)
			ps_rotate_down(a, STACK_A);
		ps_push(b, a, STACK_B);
	}
	else
	{
		while ((*a)->index != 3)
			ps_rotate_up(a, STACK_A);
		ps_push(b, a, STACK_B);
	}
	if (stack_last(*a)->index == 4)
		ps_rotate_down(a, STACK_A);
	while ((*a)->index != 4)
		ps_rotate_up(a, STACK_A);
	ps_push(b, a, STACK_B);
	sort_tiny(a);
	ps_push(a, b, STACK_A);
	ps_push(a, b, STACK_A);
	ps_rotate_up(a, STACK_A);
	ps_rotate_up(a, STACK_A);
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
				ps_rotate_up(a, STACK_A);
			else
				ps_push(b, a, STACK_B);
		}
		while (get_stack_size(*b) != 0)
			ps_push(a, b, STACK_A);
		i++;
	}
}