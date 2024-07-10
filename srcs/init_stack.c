/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:37:47 by claprand          #+#    #+#             */
/*   Updated: 2024/07/10 15:26:47 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int ac, char **av)
{
	t_stack		*a;
	long int	nb;
	int			i;

	a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&a, NULL);
		if (i == 1)
			a = stack_new(nb, 0);
		else
			stack_add_back(&a, stack_new(nb, 0));
		i++;
	}	
	return (a);
}
