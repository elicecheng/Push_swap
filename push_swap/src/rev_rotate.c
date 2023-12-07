/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:16:48 by jucheng           #+#    #+#             */
/*   Updated: 2023/11/16 14:14:12 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of a stack by 1. 
// The first element becomes the last one

void	rev_rotate(t_list **stack)
{
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = get_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}


void	do_rra(t_list **stack, bool print)
{
	rev_rotate(stack);
	if (!print)
		ft_putstr_fd("rra\n", 1);
}

void	do_rrb(t_list **stack, bool print)
{
	rev_rotate(stack);
	if (!print)
		ft_putstr_fd("rrb\n", 1);
}

void	do_rrr(t_list **stack_a, t_list **stack_b, bool print)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (!print)
		ft_putstr_fd("rrr\n", 1);
}
