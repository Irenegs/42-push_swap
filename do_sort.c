/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:48:08 by irgonzal          #+#    #+#             */
/*   Updated: 2023/07/27 19:46:38 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

void    all_back(stack **orig, stack **aux)
{
    while (*aux)
        do_push(aux, orig, 'a');
}

int all_sorted(stack **orig, stack **b)
{
    if (stack_sorted(orig) == 1)
    {
        if (stack_rev_sorted(b) == 1)
        {
            if ((*orig)->content == (*b)->content + 1)
                return (1);
        }
    }
    return (0);
}

void    sort_original(stack **orig, int n)
{
    stack   *aux;
    stack   *b;
    int     p;
    int     i;

    p = 1;
    b = NULL;
    //printf("\n[1]\n");
    while (all_sorted(orig, &b) == 0 && p < n)
    {
        i = 1;
        while (all_sorted(orig, &b) == 0 && i <= 10 && i * p < n && (*orig))
        {
            aux = (*orig)->prev;
            while (aux != (*orig) && all_sorted(orig, &b) == 0)
            {
                if (((*orig)->content / p )% 10 < i)
                    do_push(orig, &b, 'b');
                else
                    do_rotate(orig, 1, 'a');
            }
            if (((*orig)->content / p )% 10 < i)
                do_push(orig, &b, 'b');
            else
                do_rotate(orig, 1, 'a');
            //pintastack(&b);
            //pintastack(orig);
            i++;
        }
        p = p * 10;
        if (p < n)
        {
            i = n / p;
            while (i >= 0 && b)
            {
                aux = b->prev;
                while (aux != b)
                {
                    if ((b->content / p )% 10 > i)
                        do_push(&b, orig, 'a');
                    else
                        do_rotate(&b, 1, 'b');
                }
                if ((b->content / p )% 10 > i)
                    do_push(&b, orig, 'a');
                else
                    do_rotate(&b, 1, 'b');
                i--;
            }
        }
        p = p * 10;
        //all_back(orig, &b);
    }
    //pintastack(orig);
    //printf("\n[3]\n");
    all_back(orig, &b);
}

/*

while (p < n)
    {
        i = 1;
        while (i <= 10 && i * p < n && (*orig))
        {
            aux = (*orig)->prev;
            while (aux != (*orig))
            {
                if (((*orig)->content / p )% 10 < i)
                    do_push(orig, &b, 'b');
                else
                    do_rotate(orig, 1, 'a');
            }
            if (((*orig)->content / p )% 10 < i)
                do_push(orig, &b, 'b');
            else
                do_rotate(orig, 1, 'a');
            //pintastack(&b);
            //pintastack(orig);
            i++;
        }
        p = p * 10;
        if (p < n)
        {
            i = n / p;
            while (i >= 0 && b)
            {
                aux = b->prev;
                while (aux != b)
                {
                    if ((b->content / p )% 10 > i)
                        do_push(&b, orig, 'a');
                    else
                        do_rotate(&b, 1, 'b');
                }
                if ((b->content / p )% 10 > i)
                    do_push(&b, orig, 'a');
                else
                    do_rotate(&b, 1, 'b');
                i--;
            }
        }
    }
*/