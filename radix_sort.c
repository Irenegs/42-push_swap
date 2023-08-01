/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:08:03 by irgonzal          #+#    #+#             */
/*   Updated: 2023/07/22 18:40:54 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

void    sort_original(stack **orig, int n)
{
    stack *aux;
    int i;
    stack *b;
    int r;
    
    n--;
    if (stack_sorted(orig) == 1)
        return ;
    i = 1;
    b = NULL;//funciona?
    //parte 1: llevar los grupos
    while (i < 6)
    {
        aux = (*orig)->prev;
        while (aux != (*orig))
        {
            if ((*orig)->content < n /5 * i)
                do_push(orig, &b, 'b');
            else
                do_rotate(orig, 1, 'a');
        }
        i++;
    }
    //printf("A entre fases\n");
    //pintastack(orig);
    //pintastack(&b);
    i = 49;
    if ((*orig)->content < n/50 * i)
    {
        do_push(orig, &b, 'b');
    }
    while (b)
    {
        i = 0;
        r = 0;
        while (i < n / 50)
        {
            while 
            if (b->content < )
            {
                do_push(&b, orig, 'a');
                i++;
            }
            else
            {
                do_rotate(&b, 1, 'b');
                r++;
            }
        }
    }
    
}


/*

    r = 0;
    if ((*orig)->content != n - 1)
    {
        do_push(orig, &b, 'b');
        while (b->content != n - 1)
        {
            r++;
            do_rotate(&b, 1, 'b');
        }
        do_push(&b, orig, 'a');
        //printf("\n[añdk fjañsdjfkadskñfjasdkjfkñsdfjsfjñsdkfjñasjfjasfjsñ]\n");
    }
    //parte 2: devolver los grupos ordenados
    //pintastack(&b);
    while (b)
    {
        i = 0;
        aux = b;
        while (i < r  && aux->content != (*orig)->content - 1)
            aux = aux->prev;
        if (i < r)
        {
            r = r - i;
            while (i-- > 0)
                do_rotate(&b, -1, 'b');
        }
        //printf("\n[orig, orig.prev, b]:%d %d %d\n", (*orig)->content, (*orig)->prev->content, b->content);
        if (b->content == (*orig)->content - 1)
            do_push(&b, orig, 'a');
        else
        {
            do_rotate(&b, 1, 'b');
            r++;
        }
        //pintastack(&b);
    }
*/