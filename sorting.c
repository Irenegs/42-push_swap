/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:02:49 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/16 18:03:19 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

int just_rotate(stack **s, int order)
{
    stack   *aux;
    int     jumps;
    
    jumps = 0;
    if (s && (*s))
    {
        aux = (*s)->next;
        if ((*s)->content - (*s)->prev->content != order)
            jumps = 1;
        while (aux != (*s) && jumps < 2)
        {
            if (aux->content - aux->prev->content != order)
                jumps++;
            aux = aux->next;
        }
    }
    return (jumps);
}

int way_to_rotate(stack **s, int order)
{
    stack   *right;
    stack   *left;

    if (!s || !(*s))
        return (0);
    right = (*s)->next;
    left = (*s)->prev;
    while (right != left && right != left->next)
    {
        if (right->content - right->prev->content != order)
            return (1);
        else if (left->content - left->prev->content != order)
            return (-1);
        right = right->next;
        left = left->prev;
    }
    return (1);
}

void    sort_auxiliar(stack **a, stack **b)
{
    int moves_to_original;

    if (stack_sorted(b, -1) == 1)
        return ;
    if (just_rotate(b, -1) == 1)
    {
        while (stack_sorted(b, -1) == 0)
            do_rotate(b, way_to_rotate(b, -1), 'b');
        return ;
    }
    moves_to_original = 0;
    while (stack_sorted(b, -1) != 1)
    {
        do_swap(b, 'b');
        if (stack_sorted(b, -1) == 0)
        {
            do_push(b, a, 'a');
            moves_to_original++;
        }
    }
    while (moves_to_original-- > 0)
        do_push(a, b, 'b');
}

int decide_operation(stack **a)
{
    if ((*a)->content < (*a)->next->content
        && (*a)->content < (*a)->prev->content)
        return (0);
    else if ((*a)->next->content < (*a)->prev->content
        && (*a)->content < (*a)->next->next->content)
        return (1);
    else if ((*a)->next->content < (*a)->prev->content)
        return (2);
    else
        return (3);
}

void    sort_stack(stack **a)
{
    stack   *b;

    b = NULL;
    while (all_sorted(a, &b) != 1)
    {
        if (just_rotate(a, 1) == 1)
        {
            while (stack_sorted(a, 1) != 1)
                do_rotate(a, way_to_rotate(a, 1), 'a');
            break ;
        }
        else if (decide_operation(a) == 0)
        {
            do_push(a, &b, 'b');
            sort_auxiliar(a, &b);
        }
        else if (decide_operation(a) == 1)
            do_swap(a, 'a');
        else if (decide_operation(a) == 2)
            do_rotate(a, 1, 'a');
        else
            do_rotate(a, -1, 'a');
    }
    all_back(a, &b);
}
