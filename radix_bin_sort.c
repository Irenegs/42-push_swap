/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_bin_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:14:33 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/22 19:24:41 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

int	max_bit(int n)
{
	int	i;

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

void	separate_by_bit(t_stack **a, t_stack **b, int n, int bit)
{
	while ((*a) && n > 0)
	{
		if ((((*a)->content >> bit) & 1) != 0)
			do_rotate(a, 1, 'a');
		else
			do_push(a, b, 'b');
		n--;
	}
}

void	radix_bin_sort(t_stack **a, int n)
{
	int		mbit;
	t_stack	*b;
	int		bit;

	bit = 0;
	mbit = max_bit(n);
	b = NULL;
	while (stack_sorted(a, 1) != 1 && bit <= mbit)
	{
		separate_by_bit(a, &b, n, bit);
		all_back(a, &b);
		bit++;
	}
}
