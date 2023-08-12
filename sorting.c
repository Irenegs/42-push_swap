/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:02:49 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/12 17:21:47 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

void    sort_auxiliar(stack **orig, stack **b)
{
    int     moves_to_original;

    if (just_rotate(b, -1) < 2)
    {
        while (just_rotate(b, -1) == 1 && (*b)->content < (*b)->prev->content)
            do_rotate(b, 1, 'b');
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
        do_push(b, orig, 'a');
        moves_to_original++;
    }
    while (moves_to_original > 0)
    {
        do_push(orig, b, 'b');
        moves_to_original--;
    }
}

/*
void    sort_auxiliar(stack **orig, stack **aux)
{
    if ((*aux)->content < (*aux)->next->content)
    {
        do_swap(aux, 'b');
        do_push(aux, orig, 'a');
        sort_auxiliar(orig, aux);
    }
}
*/

void    sort_stack(stack **orig)
{
    stack   *b;

    b = NULL;
    //pintastack(orig);
    while (all_sorted(orig, &b) != 1)
    {
        //pintastack(orig);
        //printf("%d %d\n", stack_sorted(orig), stack_rev_sorted(&b));
        while (just_rotate(orig, 1) == 1 && (*orig)->content > (*orig)->prev->content)
            do_rotate(orig, 1, 'a');
        if ((*orig)->content < (*orig)->next->content && (*orig)->content < (*orig)->prev->content)
        {
            do_push(orig, &b, 'b');
            sort_auxiliar(orig, &b);
        }
        else if ((*orig)->content < (*orig)->next->content)
            do_rotate(orig, -1, 'a');
        else if ((*orig)->content < (*orig)->next->next->content)
            do_swap(orig, 'a');
        else
            do_rotate(orig, 1, 'a');   
    }
    all_back(orig, &b);
    free(b);
}
/*
void    sort_stack(stack **orig)
{
    stack   *aux;
    int     p;
    
    aux = create_node(-2147483648);
    p = 0;
    while (stack_sorted(orig) != 1 || (*orig)->content < aux->content)
    {
        //printf("Orig: %d %d %d\n", (*orig)->content, (*orig)->next->content, (*orig)->prev->content);
        if ((*orig)->content < (*orig)->next->content && (*orig)->content < (*orig)->prev->content)
        {
            if (p != 0)
            {
                do_push(orig, &aux, 'b');
                sort_auxiliar(orig, &aux);
            }
            else
            {
                aux = extract_node(orig);
                write(1, "pb\n", 3);
                p = 1;
            }
        }
        else if ((*orig)->content < (*orig)->next->content)
            do_rotate(orig, -1, 'a');
        else if ((*orig)->content < (*orig)->next->next->content)
            do_swap(orig, 'a');
        else
            do_rotate(orig, 1, 'a');
    }
    if (p == 1)
        all_back(orig, &aux);
    free(aux);
}
*/