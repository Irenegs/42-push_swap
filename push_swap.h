/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:26:40 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/22 19:02:36 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct t_list
{
	int				content;
	struct t_list	*next;
	struct t_list	*prev;
}					t_stack;

t_stack	*create_node(int content);
void	add_stack(t_stack **lst, t_stack *new);
void	add_below(t_stack **lst, t_stack *new);
t_stack	*extract_node(t_stack **lst);
void	clear_all_stack(t_stack **s);
void	swap(t_stack **lst);
void	rotate(t_stack **lst, int way);
void	push(t_stack **src, t_stack **dst);
void	swap_both(t_stack **st_a, t_stack **st_b);
void	rotate_both(t_stack **st_a, t_stack **st_b, int way);
void	do_swap(t_stack **lst, char t_stack_name);
void	do_rotate(t_stack **lst, int way, char t_stack_name);
void	do_push(t_stack **src, t_stack **dst, char dst_name);
void	do_swap_both(t_stack **st_a, t_stack **st_b);
void	do_rotate_both(t_stack **st_a, t_stack **st_b, int way);
int		lst2stack(int argc, char **argv, t_stack **lst);
void	sort_auxiliar(t_stack **orig, t_stack **aux);
void	all_back(t_stack **orig, t_stack **aux);
void	sort_original(t_stack **orig, int n);
void	radix_bin_sort(t_stack **orig, int n);
void	sort_stack(t_stack **orig);
int		stack_sorted(t_stack **lst, int order);
int		all_sorted(t_stack **a, t_stack **b);
int		*validate_input_normal(int argc, char **argv);
int		just_rotate(t_stack **s, int order);
int		way_to_rotate(t_stack **s, int order);

#endif
