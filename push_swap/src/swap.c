/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:02:19 by jucheng           #+#    #+#             */
/*   Updated: 2023/11/09 16:45:18 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa :swaps the 2 top elements of stack a
*  sb: swaps the 2 top elements of stack b
*  ss: sa + sb
*/
void swap (t_list **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void do_sa(t_list **stack_a, bool	print)
{
	swap(stack_a);
	if (!print)
		ft_putstr_fd("sa\n", 1);
}

void do_sb(t_list **stack_b, bool print)
{
	swap(stack_b);
	if (!print)
		ft_putstr_fd("sb\n", 1);
}

void do_ss(t_list **stack_a, t_list **stack_b, bool print)
{
	swap(stack_a);
	swap(stack_b);
	if (!print)
		ft_putstr_fd("ss\n", 1);
}