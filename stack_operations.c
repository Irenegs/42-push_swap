/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:57:12 by irgonzal          #+#    #+#             */
/*   Updated: 2023/05/03 20:05:44 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

void    swap(stack **lst)
{
    stack   *aux;
    
    (*lst)->next->prev = (*lst)->prev;
    (*lst)->prev->next = (*lst)->next;
    (*lst)->prev = (*lst)->next;
    (*lst)->next->next->prev = (*lst);
    aux = (*lst)->next->next;
    (*lst)->next->next = (*lst);
    (*lst)->next = aux;       
    *lst = (*lst)->prev;
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

    if (!*src)
        return ;
    aux = extract_stack(src);
    if (!*dst)
        *dst = aux;
    else
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