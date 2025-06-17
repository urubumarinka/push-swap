/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:52:14 by maborges          #+#    #+#             */
/*   Updated: 2025/06/18 00:16:33 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//Mock Fx to trick compiler flags
void	algo_multi(t_node **stack_a, t_node **stack_b)
{
	t_node *first;
	t_node *second;

	first = *stack_a;
	second = *stack_b;

	first->next = NULL;
	second->next = NULL;
}

