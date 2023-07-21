/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:02:49 by irgonzal          #+#    #+#             */
/*   Updated: 2023/07/20 18:27:28 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"
/*
void    sort_auxiliar(stack **orig, stack **aux)
{
    int     moves_to_original;

    moves_to_original = 0;
    if ((*aux)->content < (*aux)->prev->content)
    {
        do_rotate(aux, 1, 'b');
        return ;
    }
    while ((*aux)->content < (*aux)->next->content)
    {
        do_swap(aux, 'b');
        do_push(aux, orig, 'a');
        moves_to_original++;
    }
    while (moves_to_original > 0)
    {
        do_push(orig, aux, 'b');
        moves_to_original--;
    }
}
*/


void    sort_auxiliar(stack **orig, stack **aux)
{
    if ((*aux)->content < (*aux)->next->content)
    {
        do_swap(aux, 'b');
        do_push(aux, orig, 'a');
        sort_auxiliar(orig, aux);
    }
}


void    all_back(stack **orig, stack **aux)
{
    while (*aux)
        do_push(aux, orig, 'a');
}

void    sort_original(stack **orig)
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