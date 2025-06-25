/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:42:54 by maborges          #+#    #+#             */
/*   Updated: 2025/06/25 13:28:36 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/inc/ft_printf.h"
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // take it out at the end
# include <stdbool.h> // check if I use bool flags or 0 1 flags

//Data holding struct for stacks

typedef struct s_node
{
	int						num;
	int						index;
	int						cost;
	bool					above_median;
	bool					cheapest;
	struct s_node			*target_node;
	struct s_node			*next;
	struct s_node			*prev;
}	t_node;

//Error Handlers
void			error_msg(void);
void			free_and_error(t_node **stack);
void			free_stack(t_node **stack);

//stack
char			**split(char *s, char c);
void			init_stack_a(t_node **stack_a, char **av);
void			get_index_median(t_node *stack);
int				stack_sorted(t_node *stack);



//Push_Swap Utils
char			*ft_strchr(const char *s, int c);
t_node			*find_max(t_node *stack);
int				stack_len(t_node *stack);
t_node			*find_last(t_node *stack);
void			prepare_node_a(t_node *stack_a, t_node *stack_b);
void			find_target_a2b(t_node *stack_a, t_node *stack_b);
void			set_cheapest(t_node *stack);
t_node			*get_cheapest(t_node *stack);
t_node			*find_min(t_node *stack);
void			put_on_top(t_node **stack, t_node *cheapest, char stack_name);


//Commands
void			sa(t_node **stack_a);
void			sb(t_node **stack_b);
void			ss(t_node **stack_a, t_node **stack_b);

void			ra(t_node **stack_a);
void			rb(t_node **stack_b);
void			rr(t_node **stack_a, t_node **stack_b, t_node *cheapest);

void			rra(t_node **stack_a);
void			rrb(t_node **stack_b);
void			rrr(t_node **stack_a, t_node **stack_b, t_node *cheapest);

void			pa(t_node **stack_a, t_node**stack_b);
void			pb(t_node **stack_b, t_node **stack_a);

//Algorithm

void			algo_three(t_node **stack_a);
void			algo_multi(t_node **stack_a, t_node **stack_b);

#endif
