#include "push_swap.h"

void	ps_swap(t_stack *stack, int id)
{
	int		value;

	value = stack->next->value;
	stack->next->value = stack->value;
	stack->value = value;
	if (id == STACK_A)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	ps_push(t_stack **destination, t_stack **source, int id)
{
	t_stack	*tmp;

	tmp = (*source)->next;
	(*source)->next = (*destination);
	(*destination) = (*source);
	(*source) = tmp;
	if (id == STACK_A)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	ps_rotate_up(t_stack **head, int id)
{
	t_stack	*tmp;

	tmp = (*head);
	(*head) = (*head)->next;
	tmp->next = NULL;
	stack_last(*head)->next = tmp;
	if (id == STACK_A)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	ps_rotate_down(t_stack **head, int id)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = (*head);
	(*head) = tmp->next;
	tmp->next = NULL;
	if (id == STACK_A)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}