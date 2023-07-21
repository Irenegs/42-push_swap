/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:08:03 by irgonzal          #+#    #+#             */
/*   Updated: 2023/07/21 19:49:12 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

void    sort_original(stack **orig, int n)
{
    stack *aux;
    int i;
    stack *b;
    
    n--;
    if (stack_sorted(orig) == 1)
        return ;
    i = 1;
    b = NULL;//funciona?
    //parte 1: llevar los grupos
    while (i < 11)
    {
        aux = (*orig)->prev;
        while (aux != (*orig))
        {
            if ((*orig)->content < n /10 * i)
                do_push(orig, &b, 'b');
            else
                do_rotate(orig, 1, 'a');
        }
        i++;
    }
    //printf("A entre fases\n");
    //pintastack(orig);
    if ((*orig)->content != n - 1)
    {
        do_push(orig, &b, 'b');
        while (b->content != n - 1)
            do_rotate(&b, 1, 'b');
        do_push(&b, orig, 'a');
        //printf("\n[añdk fjañsdjfkadskñfjasdkjfkñsdfjsfjñsdkfjñasjfjasfjsñ]\n");
    }
    //parte 2: devolver los grupos ordenados
    //pintastack(&b);
    while (b)
    {
        //printf("\n[orig, orig.prev, b]:%d %d %d\n", (*orig)->content, (*orig)->prev->content, b->content);
        if (b->prev->content == (*orig)->content - 1 && b->prev != b)
            do_rotate(&b, -1, 'b');
        if (b->content == (*orig)->content - 1)
            do_push(&b, orig, 'a');
        else
            do_rotate(&b, 1, 'b');
        //pintastack(&b);
    }
    //pintastack(&b);
}
