/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:55:43 by maborges          #+#    #+#             */
/*   Updated: 2025/06/26 18:30:38 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*find_min(t_node *stack)
{
	t_node	*node_min;
	long	min_num;

	min_num = LONG_MAX;
	node_min = NULL;
	while (stack)
	{
		if (stack->num < min_num)
		{
			node_min = stack;
			min_num = stack->num;
		}
		stack = stack->next;
	}
	return (node_min);
}

void	put_on_top(t_node **stack, t_node *cheapest, char stack_name)
{
	while (*stack != cheapest)
	{
		get_index_median(*stack);
		if (stack_name == 'a')
		{
			if (cheapest->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (cheapest->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
