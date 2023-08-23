/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:35:18 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/22 18:55:40 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

void	do_swap(t_stack **lst, char t_stack_name)
{
	write(1, "s", 1);
	write(1, &t_stack_name, 1);
	write(1, "\n", 1);
	swap(lst);
}

void	do_rotate(t_stack **lst, int way, char t_stack_name)
{
	if (way == 1)
		write(1, "r", 1);
	else
		write(1, "rr", 2);
	write(1, &t_stack_name, 1);
	write(1, "\n", 1);
	rotate(lst, way);
}

void	do_push(t_stack **src, t_stack **dst, char dst_name)
{
	write(1, "p", 1);
	write(1, &dst_name, 1);
	write(1, "\n", 1);
	push(src, dst);
}

void	do_swap_both(t_stack **st_a, t_stack **st_b)
{
	write(1, "ss\n", 3);
	swap_both(st_a, st_b);
}

void	do_rotate_both(t_stack **st_a, t_stack **st_b, int way)
{
	if (way == 1)
		write(1, "rr\n", 3);
	else
		write(1, "rrr\n", 4);
	rotate_both(st_a, st_b, way);
}
