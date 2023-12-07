/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:10:41 by jucheng           #+#    #+#             */
/*   Updated: 2023/11/16 14:38:03 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push:
*	Pushes the top element of src stack to the top of dest stack.
*/

void	push(t_list **dst, t_list **src)
{
	t_list	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

/*
* pa (push a): Take the first element at the top of b 
* and put it at the top of a.
* Do nothing if b is empty.
*/

void	do_pa(t_list **stack_a, t_list **stack_b, bool print)
{
	push(stack_a, stack_b);
	if (!print)
		ft_putstr_fd("pa\n", 1);
}

/*
* pb (push b): Take the first element at the top of a 
* and put it at the top of b.
* Do nothing if a is empty.
*/

void	do_pb(t_list **stack_b, t_list **stack_a, bool print)
{
	push(stack_b, stack_a);
	if (!print)
		ft_putstr_fd("pb\n", 1);
}
