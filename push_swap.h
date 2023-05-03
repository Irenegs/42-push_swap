/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:26:40 by irgonzal          #+#    #+#             */
/*   Updated: 2023/05/03 20:06:59 by irgonzal         ###   ########.fr       */
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

stack	*create_stack(int content);
void    add_stack(stack **lst, stack *new);
stack   *extract_stack(stack **lst);
void    clear_all_stack(stack **lst);
void    swap(stack **lst);
void    rotate(stack **lst, int way);
void    push(stack **src, stack **dst);
void    swap_both(stack **st_a, stack **st_b);
void    rotate_both(stack **st_a, stack **st_b, int way);
#endif