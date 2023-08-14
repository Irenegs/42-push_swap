/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_bin_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:14:33 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/13 19:13:49 by irgonzal         ###   ########.fr       */
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

void    separate_by_bit(stack **a, stack **b, int n, int bit)
{
    /*int count;
    
    if (n > (1 << (bit + 1)))
        count = n / 2 + (n % (1 << (bit + 1))/ 2);
    else
        count = 1 << bit;
    printf("count %d\n", count);*/
    while ((*a) && n > 0)
    {
        if ((((*a)->content >> bit) & 1) != 0)
            do_rotate(a, 1, 'a');
        else
            do_push(a, b, 'b');
        n--;
    }
}

void    radix_bin_sort(stack **a, int n)
{
    int     mbit;
    stack   *b;
    int     bit;

    bit = 0;
    mbit = max_bit(n);
    //printf("max bit %d\n", mbit);
    b = NULL;
    while (stack_sorted(a, 1) != 1 && bit <= mbit)
    {
        //printf("bit %d\n", bit);
        separate_by_bit(a, &b, n, bit);
        //pintastack(a);
        //pintastack(&b);
        all_back(a, &b);
        bit++;
    }
    //pintastack(a);
}