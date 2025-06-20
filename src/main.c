/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:33:27 by maborges          #+#    #+#             */
/*   Updated: 2025/06/19 13:41:23 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	stack_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);

}

static void	choose_algo(t_node **stack_a, t_node **stack_b)
{
	if (stack_len(*stack_a) == 2)
		sa(stack_a);
	else if (stack_len(*stack_a) == 3)
		algo_three(stack_a);
	else
		algo_multi(stack_a, stack_b);
}

static void	free_split(char **av)
{
    int i = 0;
    if (!av)
        return;
    while (av[i])
        free(av[i++]);
    free(av);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		error_msg();
	else if (ac == 2)
	{
		av = split(av[1], ' ');
		init_stack_a(&stack_a, av);
		free_split(av);
	}
	else if (ac > 2)
	{
		while (++i < ac)
			if (ft_strchr(av[i], ' '))
				error_msg();
		init_stack_a(&stack_a, av);
	}
	if (!stack_sorted(stack_a))
		choose_algo(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}

/* 	for (int i = 0; av[i] != NULL; i++)
		printf("%s\n", av[i]); */

/* while (stack_a != NULL)
{
	printf("%d\n", (*stack_a).num);
	stack_a = (*stack_a).next;
} */
