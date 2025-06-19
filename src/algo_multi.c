/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:52:14 by maborges          #+#    #+#             */
/*   Updated: 2025/06/19 22:51:20 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

void	algo_multi(t_node **stack_a, t_node **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a > 3)
	{
		get_index_median(*stack_a);
		//should I call get indes median also with stack_b? thats whay I need to send to nodes to b first of all?
		//push the cheapest a node to b till there is only 3 left

	}
	algo_three(*stack_a);
	while(*stack_b)
	{
		//push to a all nodes
	}
	//check if min is on top
}

