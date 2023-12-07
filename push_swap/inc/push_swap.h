/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:46:42 by jucheng           #+#    #+#             */
/*   Updated: 2023/12/07 11:23:51 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../inc/libft.h"
# include "../inc/ft_printf.h"
# include "stdbool.h"
# include <limits.h>

typedef struct s_list 
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_med;
	bool			cheapest;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

/* initialisation */
void			initial_node_a(t_list *a, t_list *b);
void			initial_node_b(t_list *a, t_list *b);
void 			initial_stack_a(t_list **a, char **av);
//char			**split(char *s, char c);

/* operation */
void			do_rra(t_list **stack, bool print);
void			do_rrb(t_list **stack, bool print);
void			do_rrr(t_list **stack_a, t_list **stack_b, bool print);
void			do_pa(t_list **stack_a, t_list **stack_b, bool print);
void			do_pb(t_list **stack_b, t_list **stack_a, bool print);
void			do_ra(t_list **stack_a, bool print);
void			do_rb(t_list **stack_b, bool print);
void			do_rr(t_list **stack_a, t_list **stack_b, bool print);
void 			do_sa(t_list **stack_a, bool print);
void 			do_sb(t_list **stack_b, bool print);
void 			do_ss(t_list **stack_a, t_list **stack_b, bool print);


/* Sorting Algorithms */
void			sort_three(t_list **a);
void			sort_stack(t_list **a, t_list **b);


/* Error handling */
void			free_stack(t_list	**stack);
void			free_err(t_list **a);
int				syn_err(char *str);
int				is_duplicate(t_list *a, int n);


/* Utilis */
void			get_index(t_list *stack);
t_list 			*get_min(t_list *stack);
t_list 			*get_max(t_list *stack);
t_list 			*get_last(t_list *stack);
void			get_cheapest(t_list *stack);
bool 			is_sorted(t_list *stack);
int				stack_size(t_list *stack);
t_list			*find_cheapest(t_list *stack);
void			get_push(t_list **stack, t_list *top_node, char s);
//void		rev_rotate_both(t_list **a, t_list **b, t_list *cheapest);
//void		rotate_both(t_list **a, t_list **b, t_list *cheapest);

#endif