/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:50:12 by jucheng           #+#    #+#             */
/*   Updated: 2023/11/16 14:42:59 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* rra (reverse rotate a): Shift down all elements of stack a by 1.
* The last element becomes the first one.
* rrb (reverse rotate b): Shift down all elements of stack b by 1. 
* The last element becomes the first one.
* rrr : rra and rrb at the same time.
*/

void	rotate(t_list **stack)
{
	t_list	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = get_last(*stack); 
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	do_ra(t_list **stack_a, bool print)
{
	rotate(stack_a);
	if (!print)
		ft_putstr_fd("ra\n", 1);
}

void	do_rb(t_list **stack_b, bool print)
{
	rotate(stack_b);
	if (!print)
		ft_putstr_fd("rb\n", 1);
}

void	do_rr(t_list **stack_a, t_list **stack_b, bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!print)
		ft_putstr_fd("rr\n", 1);
}