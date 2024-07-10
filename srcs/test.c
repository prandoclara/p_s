// void	sort_four(t_stack **a, t_stack **b)
// {
// 	while ((*a)->index != 0)
// 		do_rra(a);
// 	do_pb(b, a);
// 	sort_tiny(a);
// 	do_pa(a, b);
// 	do_rra(a);
// }

// void	sort_five(t_stack **a, t_stack **b)
// {
// 	if (stack_last(*a)->index == 3 || (*a)->next->next->next->index == 3)
// 	{
// 		while ((*a)->index != 3)
// 			do_ra(a);
// 		do_pa(b, a);
// 	}
// 	else
// 	{
// 		while ((*a)->index != 3)
// 			do_rra(a);
// 		do_pa(a, b);
// 	}
// 	if (stack_last(*a)->index == 4)
// 		do_ra(a);
// 	while ((*a)->index != 4)
// 		do_rra(a);
// 	do_pa(b, a);
// 	sort_tiny(a);
// 	do_pb(a, b);
// 	do_pb(a, b);
// 	do_rra(a);
// 	do_rra(a);
// }