/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_node_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:43:11 by maborges          #+#    #+#             */
/*   Updated: 2025/06/25 13:02:08 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	find_target_b2a(t_node *stack_b, t_node *stack_a)
{
	t_node	*best_target;
	t_node	*current_a;
	long	match;

	while (stack_b)
	{
		match = LONG_MIN;
		best_target = NULL;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->num < stack_b->num && current_a->num > match)
			{
				match = current_a->num;
				best_target = current_a;
			}
			current_a = current_a->next;
		}
		if (match == LONG_MIN)
			best_target = find_min(stack_a);
		stack_b->target_node = best_target;
		stack_b = stack_b->next;
	}
}

void	prepare_node_b(t_node *stack_a, t_node *stack_b)
{
	get_index_median(stack_a);
	get_index_median(stack_b);
	find_target_b2a(stack_b, stack_a);
}
