/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:19:10 by maborges          #+#    #+#             */
/*   Updated: 2025/06/26 20:28:21 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	validity_checker(char *arg)
{
	int	i;

	i = 0;
	if (!arg || !arg[0])
		return (0);
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
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

static int	duplicate_checker(t_node *stack_a, int nbr)
{
	while (stack_a)
	{
		if (stack_a->num == nbr)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

static int	create_new_node(t_node **stack_a, int nbr)
{
	t_node	*new;
	t_node	*tmp;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->num = nbr;
	new->index = 0;
	new->cost = 0;
	new->cheapest = false;
	new->above_median = false;
	new->target_node = NULL;
	new->next = NULL;
	new->prev = NULL;
	if (!*stack_a)
		return (*stack_a = new, 1);
	tmp = *stack_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	return (1);
}

void	init_stack_a(t_node **stack_a, char **av)
{
	int		i;
	long	num;

	i = 0;
	while (av[i])
	{
		if (!validity_checker(av[i]))
			free_and_error(stack_a);
		num = ft_atol(av[i]);
		if (num < INT_MIN || num > INT_MAX)
			free_and_error(stack_a);
		if (!duplicate_checker(*stack_a, (int)num))
			free_and_error(stack_a);
		if (!create_new_node(stack_a, (int)num))
			free_and_error(stack_a);
		i++;
	}
}
