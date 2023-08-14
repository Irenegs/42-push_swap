/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:02:49 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/14 18:42:30 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

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
    //pintastack(b);
    moves_to_original = 0;
    while (stack_sorted(b, -1) != 1)
    {
        do_swap(b, 'b');
        if (stack_sorted(b, -1) == 0)
        {
            //printf("b sorted %d\n", stack_sorted(b, -1));
            do_push(b, a, 'a');
            moves_to_original++;
        }
    }
    while (moves_to_original-- > 0)
        do_push(a, b, 'b');
}
/*
void    sort_auxiliar(stack **a, stack **b)
{
    int     moves_to_original;

    if (just_rotate(b, -1) < 2)
    {
        while ((*b)->content < (*b)->prev->content)
            do_rotate(b, way_to_rotate(b, -1), 'b');
        return ;
    }
    moves_to_original = 0;
    if ((*b)->content < (*b)->prev->content)
    {
        do_rotate(b, 1, 'b');
        return ;
    }
    while ((*b)->content < (*b)->next->content)
    {
        do_swap(b, 'b');
        if ()
        do_push(b, a, 'a');
        moves_to_original++;
    }
    while (moves_to_original > 0)
    {
        do_push(a, b, 'b');
        moves_to_original--;
    }
}
*/
/*
void    sort_auxiliar(stack **a, stack **aux)
{
    if ((*aux)->content < (*aux)->next->content)
    {
        do_swap(aux, 'b');
        do_push(aux, a, 'a');
        sort_auxiliar(a, aux);
    }
}
*/

void    sort_stack(stack **a)
{
    stack   *b;

    b = NULL;
    //pintastack(a);
    while (all_sorted(a, &b) != 1)
    {
        if (just_rotate(a, 1) == 1)
        {
            while (stack_sorted(a, 1) != 1)
                do_rotate(a, way_to_rotate(a, 1), 'a');
            break ;
        }
        else if ((*a)->content < (*a)->next->content && (*a)->content < (*a)->prev->content)
        {
            do_push(a, &b, 'b');
            sort_auxiliar(a, &b);
        }
        else if ((*a)->next->content < (*a)->prev->content && (*a)->content < (*a)->next->next->content)
            do_swap(a, 'a');
        else if ((*a)->next->content < (*a)->prev->content)
            do_rotate(a, 1, 'a');
        else
            do_rotate(a, -1, 'a');
    }
    all_back(a, &b);
}




/*
void    sort_stack(stack **a)
{
    stack   *b;

    b = NULL;
    //pintastack(a);
    while (all_sorted(a, &b) != 1)
    {
        //pintastack(a);
        //printf("%d\n", just_rotate(a, 1));
        while (just_rotate(a, 1) == 1 && (*a)->content > (*a)->prev->content)
            do_rotate(a, way_to_rotate(a, 1), 'a');
        if ((*a)->content < (*a)->next->content && (*a)->content < (*a)->prev->content)
        {
            do_push(a, &b, 'b');
            sort_auxiliar(a, &b);
        }
        else if ((*a)->next->content < (*a)->prev->content)
            do_rotate(a, -1, 'a');
        else if ((*a)->next->content > (*a)->prev->content)
            do_rotate(a, 1, 'a');
        else if ((*a)->content < (*a)->next->next->content)
            do_swap(a, 'a');
        else
            do_rotate(a, 1, 'a');   
    }
    all_back(a, &b);
}*/