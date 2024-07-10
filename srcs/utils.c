/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:45:42 by claprand          #+#    #+#             */
/*   Updated: 2024/07/10 15:41:53 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atol(char *str)
{
	long int	nb;
	int			i;
	int			sign;

	sign = 1;
	nb = 0;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		if (nb <= INT_MIN || nb >= INT_MAX)
			return (-2147483650);
		i++;
	}
	return (nb * sign);
}

void	freestack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	exit_error(t_stack **a, t_stack **b)
{
	if (a == NULL || *a != NULL)
		freestack(a);
	if (b == NULL || *b != NULL)
		freestack(b);
	write(2, "Error\n", 6);
	exit (1);
}

int	get_stack_size(t_stack	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	get_maxbits(int size)
{
	int	max_bits;
	int	max_index;

	max_bits = 0;
	max_index = size - 1;
	while (max_index >> max_bits != 0)
		++max_bits;
	return (max_bits);
}

int		check_lst_len(t_stack *stack, int len)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
		if (i >= len)
			break ;
	}
	if (i < len)
		return (0);
	return (1);
}