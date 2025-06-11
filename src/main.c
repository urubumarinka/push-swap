/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:33:27 by maborges          #+#    #+#             */
/*   Updated: 2025/06/11 21:53:14 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	choose_algo(t_node **stack_a, t_node **stack_b)
{
	if (stack_len(stack_a) == 2)
		sa(&stack_a, false);
	else if (stack_len(stack_a) == 3)
		sort_three(&stack_a);
	else
		sort_multi(&stack_a, &stack_b);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		error_msg();
	else if (ac == 2)
		av = split(av[1], ' ');
	else if (ac > 2)
		while (++i < ac)
			if (ft_strchr(av[i], ' '))
				error_msg();
	init_stack_a(&stack_a, av);
	if (!stack_sorted(stack_a))
		choose_algo(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
/*
		for (int i = 1; av[i] != NULL; i++)
		printf("%s\n", av[i]); */
