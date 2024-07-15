/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:53:27 by claprand          #+#    #+#             */
/*   Updated: 2024/07/15 10:51:28 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

# define STACK_A 0
# define STACK_B 1

typedef struct s_stack
{
	int				value;
	int				index;
	int				nb_elem;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

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
int		is_sorted(t_stack *a);

/********* UTILS *********/
long	ft_atol(char *str);
void	freestack(t_stack **stack);
void	exit_error(t_stack **a, t_stack **b);
int		get_stack_size(t_stack	*stack);
int		get_maxbits(int size);

/********* INDEX*********/
void	create_index(t_stack *stack, int size, int value);

/********* MOVES *********/
void	do_swap(t_stack **stack, int id);
void	do_rotate(t_stack **stack, int id);
void	do_push(t_stack **destination, t_stack **source, int id);
void	do_reverse_rotate(t_stack **stack, int id);

/********* SORT *********/
void	sort_tiny(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	radix_sort(t_stack **a, t_stack **b);

#endif