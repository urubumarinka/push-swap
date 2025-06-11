/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:19:10 by maborges          #+#    #+#             */
/*   Updated: 2025/06/11 22:45:41 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Case of error, it must display "Error" followed ’\n’ on the standard error.
Errors include, for example: some arguments not being integers, some arguments
exceeding the integer limits, and/or the presence of duplicates. */



static int	validity_check(char *arg)
{

	if (!(*arg == '-' || *arg == '+' || (*arg >= '0' && *arg <= '9')))
		return (0);
	if ((*arg == '-' || *arg == '+' && !(arg[1] >= '0' && arg[1] <= '9')))
		return (0);
	while (*++arg)
	{
		if (*arg < '0' || *arg > '9')
			return (0);
	}
	return (1);
}

static long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	n;

	n = 0;
	i = 0;
	sign = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		n = (n * 10) + str[i] - '0';
		i++;
	}
	return (n * sign);
}

static int	check_duplicate(t_node *stack_a, long nbr)
{
	while (stack_a)
	{
		if (stack_a->num == nbr)
			return (0); 
		stack_a = stack_a->next;
	}
	return (1);
}

void	init_stack_a(t_node *stack_a, char **av)
{
	int		i;
	long	num;

	i = 0;
	while (av[i])
	{
		if (!validity_check(av[i]))
			free_and_error(&stack_a);
		num = ft_atol(av[i]);
		if (num < INT_MIN || num > INT_MAX)
			free_and_error(&stack_a);
		if (!check_duplicate(stack_a, num))
			free_and_error(&stack_a);
		if (!create_new_node(&stack_a, av[i]))
			free_and_error(&stack_a);
		i++;
	}
}
