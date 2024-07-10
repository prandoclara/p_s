/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:53:27 by claprand          #+#    #+#             */
/*   Updated: 2024/07/10 16:20:00 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# include "libft.h"

typedef struct s_stack
{
	int 			value;
	int 			index;
	int				a_size;
	int				b_size;
	struct s_stack	*next;
	struct s_stack	*prev;
} 					t_stack;

void	create_index(t_stack *stack);
int		check_lst_len(t_stack *stack, int len);
void	tiny_sort(t_stack **stack);


/********* INPUT_CHECK_UTILS *********/
int		ft_nbcmp(char *s1, char *s2);
int		is_sign(char c);
int		is_digit(char c);


/********* INPUT_CHECK *********/
int		is_correct_input(char **av);


/********* LST_UTILS *********/
t_stack	*stack_new(int value, int index);
void	stack_add_front(t_stack **a, t_stack *nb);
void	stack_add_back(t_stack **a, t_stack *nb);
t_stack	*stack_last(t_stack *a);
t_stack	*stack_before_last(t_stack *a);


/********* INIT_STACK *********/
t_stack	*init_stack(int ac, char **av);


/********* UTILS *********/
long	ft_atol(char *str);
void	freestack(t_stack **stack);
void	exit_error(t_stack **a, t_stack **b);
int		get_stack_size(t_stack	*stack);
int		get_maxbits(int size);


/********* SWAP *********/
void	swap(t_stack *a);
void	do_sa(t_stack **a);
void	do_sb(t_stack **b);
void	do_ss(t_stack **a, t_stack **b);


/********* ROTATE *********/
void	rotate(t_stack **a);
void	do_ra(t_stack **a);
void	do_rb(t_stack **b);
void	do_rr(t_stack **a, t_stack **b);


/********* PUSH *********/
void	push(t_stack **a, t_stack **b);
void	do_pa(t_stack **a, t_stack **b);
void	do_pb(t_stack **a, t_stack **b);


/********* REVERSE ROTATE *********/
void	reverse_rotate(t_stack **a);
void	do_rra(t_stack **a);
void	do_rrb(t_stack **b);
void	do_rrr(t_stack **a, t_stack **b);


/********* SORT *********/
void	radix_sort(t_stack **a, t_stack **b);
void	sort_tiny(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);

int	is_sorted(t_stack *a);

#endif