/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:03:57 by jucheng           #+#    #+#             */
/*   Updated: 2023/11/16 11:11:02 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Finds out the number of elements in a stack.
int	stack_size(t_list *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

// Checks if the stack is sorted in ascending order
bool is_sorted(t_list *stack)
{
	if (!stack)
		return (true);
	while(stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return(false);
		stack = stack->next;
	}
	return (true);
}

t_list *get_last(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_list *get_max(t_list *stack)
{
	long	max;
	t_list	*biggest_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	biggest_node = NULL;
	while (stack)
	{
		if (stack->value > max)
			{
				max = stack->value;
				biggest_node = stack;
			}
			stack = stack->next;
	}
	return (biggest_node);
}

t_list *get_min(t_list *stack)
{
	long	min;
	t_list	*smallest_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
			{
				min = stack->value;
				smallest_node = stack;
			}
			stack = stack->next;
	}
	return (smallest_node);
}