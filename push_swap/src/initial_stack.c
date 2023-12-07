/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:00:58 by jucheng           #+#    #+#             */
/*   Updated: 2023/11/13 18:18:05 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void append_node(t_list **stack, int n)
{
	t_list	*node;
	t_list	*last;

	if (!stack)
		return ;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = get_last(*stack);
		last->next = node;
		node->prev = last;
	}
}

void initial_stack_a(t_list **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (syn_err(av[i]))
			free_err(a);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_err(a);
		if (is_duplicate(*a, (int)n))
			free_err(a);
		append_node(a, (int)n);
		i++;
	}
}
