/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:52:14 by maborges          #+#    #+#             */
/*   Updated: 2025/06/26 20:26:56 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_a2b(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_a;

	if (!*stack_a)
		return ;
	cheapest_a = get_cheapest(*stack_a);
	if (!cheapest_a)
		return ;
	if (cheapest_a->above_median && cheapest_a->target_node->above_median)
		rr(stack_a, stack_b, cheapest_a);
	else if (!(cheapest_a->above_median)
		&& !(cheapest_a->target_node->above_median))
		rrr(stack_a, stack_b, cheapest_a);
	if (*stack_a != cheapest_a)
		put_on_top(stack_a, cheapest_a, 'a');
	if (*stack_b != cheapest_a->target_node)
		put_on_top(stack_b, cheapest_a->target_node, 'b');
	pb(stack_a, stack_b);
}

static void	push_b2a(t_node **stack_b, t_node **stack_a)
{
	t_node	*target_a;

	if (!*stack_b)
		return ;
	target_a = (*stack_b)->target_node;
	put_on_top(stack_a, target_a, 'a');
	pa(stack_b, stack_a);
}

static void	min_to_top(t_node **stack)
{
	t_node	*min;

	min = find_min(*stack);
	while (*stack != min)
	{
		if (min->above_median)
			ra(stack);
		else
			rra(stack);
		get_index_median(*stack);
	}
}

void	algo_multi(t_node **stack_a, t_node **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (len_a-- > 3 && !stack_sorted(*stack_a))
	{
		prepare_node_a(*stack_a, *stack_b);
		push_a2b(stack_a, stack_b);
	}
	algo_three(stack_a);
	while (*stack_b)
	{
		prepare_node_b(*stack_a, *stack_b);
		push_b2a(stack_b, stack_a);
	}
	get_index_median(*stack_a);
	min_to_top(stack_a);
}

