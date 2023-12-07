/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:23:32 by jucheng           #+#    #+#             */
/*   Updated: 2023/11/16 10:53:53 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_to_b(t_list *a, t_list *b)
{
	t_list	*current_a;
	t_list	*target_a;
	long	match_index;

	while (b)
	{
		match_index = LONG_MAX;
		current_a = a;
		target_a = NULL;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < match_index)
			{
				match_index = current_a->value;
				target_a = current_a;
			}
			current_a = current_a->next;
		}
		if (match_index == LONG_MAX)
			b->target = get_min(a);
		else
			b->target = target_a;
		b = b->next;
	}
}

void	initial_node_b(t_list *a, t_list *b)
{
	get_index(a);
	get_index(b);
	set_target_to_b(a, b);
}
