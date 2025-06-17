/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:55:03 by maborges          #+#    #+#             */
/*   Updated: 2025/06/18 00:05:35 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	algo_three(t_node **stack_a)
{
	t_node	*biggest;

	biggest = find_max(*stack_a);
	if (biggest == *stack_a)
		ra(stack_a);
	else if (biggest == (*stack_a)->next)
		rra(stack_a);
	if ((*stack_a)->num > (*stack_a)->next->num)
		sa(stack_a);
}
