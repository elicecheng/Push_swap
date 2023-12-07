/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:04:30 by jucheng           #+#    #+#             */
/*   Updated: 2023/11/09 16:54:40 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_push(t_list **stack, t_list *top_node, char s)
{
	while (*stack != top_node)
	{
		if (s == 'a')
		{
			if (top_node->above_med)
				do_ra(stack, false);
			else
				do_rra(stack, false);
		}
		else if (s == 'b')
		{
			if (top_node->above_med)
				do_rb(stack, false);
			else
				do_rrb(stack, false);
		}
	}
}

t_list	*find_cheapest(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
