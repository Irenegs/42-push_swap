/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_bin_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:14:33 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/10 19:21:49 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

int max_bit(int n)
{
    int i;

    if (n < 2)
        return (0);
    i = -1;
    while (n > 0)
    {
        i++;
        n = n / 2;
    }
    return (i);
}

void    separate_by_bit(stack **orig, stack **b, int n, int bit)
{
    /*int count;
    
    if (n > (1 << (bit + 1)))
        count = n / 2 + (n % (1 << (bit + 1))/ 2);
    else
        count = 1 << bit;
    printf("count %d\n", count);*/
    while ((*orig) && n > 0)
    {
        if ((((*orig)->content >> bit) & 1) != 0)
            do_rotate(orig, 1, 'a');
        else
            do_push(orig, b, 'b');
        n--;
    }
}

void    radix_bin_sort(stack **orig, int n)
{
    int     mbit;
    stack   *b;
    int     bit;

    bit = 0;
    mbit = max_bit(n);
    //printf("max bit %d\n", mbit);
    b = NULL;
    while (bit <= mbit)
    {
        //printf("bit %d\n", bit);
        separate_by_bit(orig, &b, n, bit);
        //pintastack(orig);
        //pintastack(&b);
        all_back(orig, &b);
        bit++;
    }
    //pintastack(orig);
}