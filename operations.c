/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:35:18 by irgonzal          #+#    #+#             */
/*   Updated: 2023/07/01 17:57:37 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

void    do_swap(stack **lst, char stack_name)
{
    write(1, "s", 1);
    write(1, &stack_name, 1);
    write(1, "\n", 1);
    swap(lst);
}

void    do_rotate(stack **lst, int way, char stack_name)
{
    if (way == 1)
        write(1, "r", 1);
    else
        write(1, "rr", 2);
    write(1, &stack_name, 1);
    write(1, "\n", 1);
    rotate(lst, way);
}

void    do_push(stack **src, stack **dst, char dst_name)
{
    //estaría bien que cambiara los tamaños de los stacks
    write(1, "p", 1);
    write(1, &dst_name, 1);
    write(1, "\n", 1);
    push(src, dst);
}

void    do_swap_both(stack **st_a, stack **st_b)
{
    write(1, "ss\n", 3);
    swap_both(st_a, st_b);
}

void    do_rotate_both(stack **st_a, stack **st_b, int way)
{
    if (way == 1)
        write(1, "rr\n", 3);
    else
        write(1, "rrr\n", 4);
    rotate_both(st_a, st_b, way);
}