/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:57:12 by irgonzal          #+#    #+#             */
/*   Updated: 2023/07/01 20:03:36 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

void    swap(stack **lst)
{
    int aux;
    
    aux = (*lst)->content;
    (*lst)->content = (*lst)->next->content;
    (*lst)->next->content = aux;
}

void    rotate(stack **lst, int way)
{
    if (way > 0)
        *lst = (*lst)->next;
    else
        *lst = (*lst)->prev;
}

void    push(stack **src, stack **dst)
{
    stack   *aux;

    if (!src || !*src)
        return ;
    aux = extract_node(src);
    add_stack(dst, aux);
}

void    swap_both(stack **st_a, stack **st_b)
{
    swap(st_a);
    swap(st_b);
}

void    rotate_both(stack **st_a, stack **st_b, int way)
{
    rotate(st_a, way);
    rotate(st_b, way);
}