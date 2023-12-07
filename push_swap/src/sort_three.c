/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:45:10 by jucheng           #+#    #+#             */
/*   Updated: 2023/11/16 13:33:56 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **a)
{
	t_list	*biggest_node;

	biggest_node = get_max(*a);
	if (biggest_node == *a)
		do_ra(a, false);
	else if ((*a)->next == biggest_node)
		do_rra(a, false);
	if ((*a)->value > (*a)->next->value)
		do_sa(a, false);     
}
