/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:02:43 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/14 18:42:06 by irgonzal         ###   ########.fr       */
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
        //printf("way %d %d %d\n", right->content - right->prev->content, left->content - left->prev->content,order);
        if (right->content - right->prev->content != order)
            return (1);
        else if (left->content - left->prev->content != order)
            return (-1);
        right = right->next;
        left = left->prev;
    }
    return (1);
}

void    all_back(stack **a, stack **b)
{
    while (*b)
        do_push(b, a, 'a');
}
/*
int stack_sorted(stack **s, int order)
{
    stack   *aux;
    
    if (s && *s && (*s)->content != (*s)->next->content)
    {
        aux = *s;
        while (aux->next->content != (*s)->content)
        {
            if (aux->next->content - aux->content != order)
                return (0);
            aux = aux->next;
        }
    }
    return (1);
}
*/

int stack_sorted(stack **s, int order)
{
    stack   *aux;
    
    if (s && *s && (*s)->content != (*s)->next->content)
    {
        aux = *s;
        while (aux->next->content != (*s)->content)
        {
            if ((aux->next->content - aux->content)*order < 0)
                return (0);
            aux = aux->next;
        }
    }
    return (1);
}

/*
int stack_rev_sorted(stack **s)
{
    stack   *aux;
    
    if (s && *s && (*s)->content != (*s)->next->content)
    {
        aux = *s;
        while (aux->next->content != (*s)->content)
        {
            if (aux->content != aux->next->content + 1)
                return (0);
            aux = aux->next;
        }
    }
    return (1);
}
*/
int all_sorted(stack **a, stack **b)
{
    if (stack_sorted(a, 1) == 1)
    {
        if (stack_sorted(b, -1) == 1)
        {
            if (a && b && *a && *b)
            {
                if ((*a)->content > (*b)->content)
                    return (1);
            }
            else
                return(1);
        }
    }
    return (0);
}

void    sort_original(stack **a, int n)
{
    if (stack_sorted(a, 1) != 1)
    {
        //printf("just rotate %d\n", just_rotate(a, 1));
        if (just_rotate(a, 1) == 1)
        {
            //printf("way rotate %d\n", way_to_rotate(a, 1));
            while (stack_sorted(a, 1) != 1)
                do_rotate(a, way_to_rotate(a, 1), 'a');
        }
        if (1 < n && n < 99)
            sort_stack(a);
        else
            radix_bin_sort(a, n);
    }
}
