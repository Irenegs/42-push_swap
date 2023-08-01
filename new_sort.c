/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:44:36 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/01 17:15:13 by irgonzal         ###   ########.fr       */
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
            if (!(*b) || !(*orig) || (*orig)->content == (*b)->content + 1)
                return (1);
        }
    }
    return (0);
}

int number_is_forward(stack **orig, int i, int p)
{
    stack   *aux;

    aux = (*orig)->next;
    while (aux->content / (p * 10) == i / 10 && aux != (*orig))
    {
        if (aux->content == i)
            return (1);
        aux = aux->next;
    }
    return (0);
}

int number_is_back(stack **orig, int i, int p)
{
    stack   *aux;

    aux = (*orig)->next;
    while (aux->content / (p * 10) == i / 10 && aux != (*orig))
    {
        if (aux->content == i)
            return (1);
        aux = aux->prev;
    }
    return (0);
}

int find_next(stack **s, int i, int p)
{
    stack   *right;
    stack   *left;
    
    //printf("findnext\n");
    if (!s || !(*s))
        return (0);
    //printf("find        next\n");
    right = (*s)->next;
    left = (*s)->prev;
    //printf("find_next %d\n", i);
    while (right != left || (right->content / (p * 10) == (i / 10) && right->content / (p * 10) == (i / 10)))
    {
        if (left->content / p == i)
            return (-1);
        else if (right->content / p == i)
                return (1);
        right = right->next;
        left = left->prev;
    }
    //printf("find_next %d %d-> 0\n", i, 0);
    return (0);
}
/*
void    get_chunks(stack **orig, stack **b, int n)
{
    stack   *aux;
    int     p;
    int     i;
    int     count;
    
    p = 10;
    if (n > 150)
        p = 100;
    i = 0;
    while (all_sorted(orig, b) != 1 && (i - 1) * p < n)
    {
        count = 0;
        aux = (*orig)->prev;
        while ((*orig) && aux != (*orig) && count < p)
        {
            if ((*orig)->content / p == i)
            {
                do_push(orig, b, 'b');
                count++;
            }
            else if (find_next(orig, i, 100) != 0)
            {
                while ((*orig)->content / p == i)
                    do_rotate(orig, find_next(orig, i, 100), 'a');
            }
        }
        i++;
    }
    do_push(orig, b, 'b');
    printf("1\n");  
}
*/

void    get_chunks(stack **orig, stack **b, int n)
{
    stack   *aux;
    int     p;
    int     i;
    int     count;
    
    p = 10;
    if (n > 150)
        p = 100;
    i = 1;
    while (all_sorted(orig, b) != 1 && (i - 1) * p < n)
    {
        count = 0;
        aux = (*orig)->prev;
        while (aux != (*orig) && count < p)
        {
            if ((*orig)->content < i * p)
            {
                do_push(orig, b, 'b');
                count++;
            }
            else
                do_rotate(orig, 1, 'a');
        }
        i++;
    }
    do_push(orig, b, 'b');
}

void    sort_chunks(stack **orig, stack **b, int n)
{
    int i;
    int count;

    i = n / 10;
    while (all_sorted(orig, b) != 1 && i >= 0)
    {
        count = 0;
        //printf("find_next(b, i, 10) %d -> %d", i, find_next(b, i, 10));
        while ((*b) && count < 10 && find_next(b, i, 10) != 0)
        {
            if ((*b)->content / 10 == i)
            {
                do_push(b, orig, 'a');
                count++;
            }
            else if ((*b) && find_next(b, i, 10) != 0)
            {
                while ((*b)->content / 10 != i)
                    do_rotate(b, find_next(b, i, 10), 'b');
            }
        }
        i--;
    }
}

void    final_sort(stack **orig, stack **b, int n)
{
    int i;

    i = n - 1;
    while (all_sorted(orig, b) != 1 && i >= 0)
    {
        if ((*b)->content == i)
        {
            do_push(b, orig, 'a');
            i--;
        }
        else if (find_next(b, i, 1) != 0)
        {
            //printf("[i:%d]\n", i);
            while ((*b)->content != i)
                do_rotate(b, find_next(b, i, 1), 'b');
        }
    }
}

void    final_sort_in_b(stack **orig, stack **b, int n)
{
    int i;

    i = 0;
    while (all_sorted(orig, b) != 1 && i < n)
    {
        if ((*orig)->content == i)
        {
            do_push(orig, b, 'b');
            i++;
        }
        else if (number_is_back(orig, i, 1) == 1)
        {
            while ((*orig)->content != i)
                do_rotate(orig, -1, 'a');
        }
        else
        {
            while ((*orig)->content != i)
                do_rotate(orig, 1, 'a');     
        }
    }
}

void    sort_original(stack **orig, int n)
{
    stack   *b;
    //int     p;
    //int     i;

    b = NULL;
    get_chunks(orig, &b, n);
    if (n < 150)
        final_sort(orig, &b, n);
    else
    {
        sort_chunks(orig, &b, n);
        final_sort_in_b(orig, &b, n);
    }
    //pintastack(&b);
    all_back(orig, &b);
} 
