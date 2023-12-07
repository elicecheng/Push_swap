/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:00:15 by jucheng           #+#    #+#             */
/*   Updated: 2023/11/16 15:12:33 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_list **a, t_list **b, t_list *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		do_rr(a, b, false);
	get_index(*a);
	get_index(*b);
}

void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		do_rrr(a, b, false);
	get_index(*a);
	get_index(*b);
}
void	push_a_to_b(t_list **a, t_list **b)
{
	t_list	*cheapest;

	cheapest = find_cheapest(*a);
	if (cheapest->above_med && cheapest->target->above_med)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_med) && !(cheapest->target->above_med))
		rev_rotate_both(a, b, cheapest);
	get_push(a, cheapest, 'a');
	get_push(b, cheapest->target, 'b');
	do_pb(b, a, false);
}

void	push_b_to_a(t_list **a, t_list **b)
{
	get_push(a, (*b)->target, 'a');
	do_pa(a, b, false);
}

static void	min_top(t_list **a)
{
	while ((*a)->value != get_min(*a)->value)
	{
		if (get_min(*a)->above_med)
			do_ra(a, false);
		else
			do_rra(a, false);
	}
}

void	sort_stack(t_list **a, t_list **b)
{
	int	a_size;

	a_size = stack_size(*a);
	if (a_size-- > 3 && !is_sorted(*a))
		do_pb(b, a, false);
	if (a_size-- > 3 && !is_sorted(*a))
		do_pb(b, a, false);
	while (a_size-- > 3 && !is_sorted(*a))
	{
		initial_node_a(*a, *b);
		push_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		initial_node_b(*a, *b);
		push_b_to_a(a, b);
	}
	get_index(*a);
	min_top(a);
}
