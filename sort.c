/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:02:43 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/12 17:25:44 by irgonzal         ###   ########.fr       */
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
            if (aux->content - (*s)->content != order)
                jumps++;
            aux = aux->next;
        }
    }
    return (jumps);
}

void    all_back(stack **orig, stack **aux)
{
    while (*aux)
        do_push(aux, orig, 'a');
}

int stack_sorted(stack **lst)
{
    stack   *aux;
    
    if (lst && *lst && (*lst)->content != (*lst)->next->content)
    {
        aux = *lst;
        while (aux->next->content != (*lst)->content)
        {
            if (aux->content + 1 != aux->next->content)
                return (0);
            aux = aux->next;
        }
    }
    return (1);
}

int stack_rev_sorted(stack **lst)
{
    stack   *aux;
    
    if (lst && *lst && (*lst)->content != (*lst)->next->content)
    {
        aux = *lst;
        while (aux->next->content != (*lst)->content)
        {
            if (aux->content != aux->next->content + 1)
                return (0);
            aux = aux->next;
        }
    }
    return (1);
}

int all_sorted(stack **a, stack **b)
{
    if (stack_sorted(a) == 1)
    {
        //printf("\na sorted\n");
        if (stack_rev_sorted(b) == 1)
        {
            //printf("\nb sorted \n");
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

void    sort_original(stack **orig, int n)
{
    if (n > 1 && n < 99)
        sort_stack(orig);
    else
        radix_bin_sort(orig, n);
}
