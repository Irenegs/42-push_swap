/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:26:40 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/14 18:36:22 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "libft/libft.h"

#include <stdio.h>

typedef struct d_list
{
	int			    content;
	struct d_list	*next;
    struct d_list   *prev;
}					stack;

stack	*create_node(int content);
void    add_stack(stack **lst, stack *new);
void    add_below(stack **lst, stack *new);
stack   *extract_node(stack **lst);
void    clear_all_stack(stack **lst);
void    swap(stack **lst);
void    rotate(stack **lst, int way);
void    push(stack **src, stack **dst);
void    swap_both(stack **st_a, stack **st_b);
void    rotate_both(stack **st_a, stack **st_b, int way);
void    do_swap(stack **lst, char stack_name);
void    do_rotate(stack **lst, int way, char stack_name);
void    do_push(stack **src, stack **dst, char dst_name);
void    do_swap_both(stack **st_a, stack **st_b);
void    do_rotate_both(stack **st_a, stack **st_b, int way);
int 	lst2stack(int argc, char **argv, stack **lst);
void    sort_auxiliar(stack **orig, stack **aux);
void    all_back(stack **orig, stack **aux);
void    sort_original(stack **orig, int n);
void    radix_bin_sort(stack **orig, int n);
void    sort_stack(stack **orig);
int		stack_sorted(stack **lst, int order);
//int 	stack_rev_sorted(stack **lst);
int 	all_sorted(stack **a, stack **b);
int 	*validate_input_normal(int argc, char **argv);
int 	just_rotate(stack **s, int order);
int 	way_to_rotate(stack **s, int order);

void pintastack(stack **lst);
//void pintainv(stack **lst);
#endif