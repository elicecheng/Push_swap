/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:55:52 by jucheng           #+#    #+#             */
/*   Updated: 2023/11/16 11:00:55 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index(t_list *stack)
{
	int	i;
	int	med;

	i = 0;
	if (!stack)
		return ;
	med = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= med)
			stack->above_med = true;
		else
			stack->above_med = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_to_a(t_list *a, t_list *b)
{
	t_list	*current_b;
	t_list	*target_b;
	long	match_index;

	while (a)
	{
		match_index = LONG_MIN;
		current_b = b;
		target_b = NULL;
		while (current_b)
		{
			if (current_b->value < a->value
				&& current_b->value > match_index)
			{
				match_index = current_b->value;
				target_b = current_b;
			}
			current_b = current_b->next;
		}
		if (match_index == LONG_MIN)
			a->target = get_max(b);
		else
			a->target = target_b;
		a = a->next;
	}
}

/* 
   Analyses the cost of the a node along with it's target b node, 
   which is the sum of the number of instructions for both the nodes 
   to rotate to the top of their stacks 
 */

static void	cost_analyse(t_list *a, t_list *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_size(a);
	b_len = stack_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_med))
			a->push_cost = a_len - (a->index);
		if (a->target->above_med)
			a->push_cost += a->target->index;
		else
			a->push_cost += b_len - (a->target->index);
		a = a->next;
	}
}

/* sets a node's `cheapest` attribute as `true` or `false` */
void	get_cheapest(t_list *stack)
{
	long	cheapest_value;
	t_list	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	cheapest_node = NULL;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	initial_node_a(t_list *a, t_list *b)
{
	get_index(a);
	get_index(b);
	set_target_to_a(a, b);
	cost_analyse(a, b);
	get_cheapest(a);
}
