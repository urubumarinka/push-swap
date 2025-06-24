/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_node_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:30:27 by maborges          #+#    #+#             */
/*   Updated: 2025/06/24 21:58:20 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h""

void	get_index_median(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
		{
			stack->above_median = true;
		}
		stack = stack->next;
	}
}

static void	find_target_a2b(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_b;
	t_node	*best_target;
	long	match;

	while(stack_a)
	{
		match = LONG_MIN;
		best_target = NULL;
		current_b = stack_b;
		while(current_b)
		{
			if (current_b->num < stack_a->num && current_b->num > match)
			{
				match = current_b->num;
				best_target = current_b;
			}
			current_b = current_b->next;
		}
		if (match == LONG_MIN)
			best_target = find_max(stack_b);
		stack_a->target_node = best_target;
		stack_a = stack_a->next;
	}
}

static  void	find_cost_a2b(t_node *stack_a, t_node *stack_b)
{
	t_node	*target_b;

	while (stack_a)
	{
		target_b = stack_a->target_node;
		if (stack_a->above_median)
			stack_a->cost = stack_a->index;
		else
			stack_a->cost = stack_a->index - stack_len(stack_a);
		if (target_b->above_median)
			target_b->cost = target_b->index;
		else
			target_b->cost = target_b->index - stack_len(stack_b);
		stack_a = stack_a->next;
	}
}

void	set_cheapest(t_node *stack)
{
	t_node	*cheapest;
	int		cheapest_cost;

	cheapest_cost = INT_MAX;
	cheapest = NULL;
	while (stack)
	{
		if (stack->cost < cheapest_cost)
		{
			cheapest_cost = stack->cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	if (cheapest)
		cheapest->cheapest = true;
}

void	prepare_node_a(t_node *stack_a, t_node *stack_b)
{
	get_index_median(stack_a);
	get_index_median(stack_b);
	find_target_a2b(stack_a, stack_b);
	find_cost_a2b(stack_a, stack_b);
	set_cheapest(stack_a);
}
