/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:02:43 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/23 17:30:39 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

void	all_back(t_stack **a, t_stack **b)
{
	while (*b)
		do_push(b, a, 'a');
}

int	stack_sorted(t_stack **s, int order)
{
	t_stack	*aux;

	if (s && *s && (*s)->content != (*s)->next->content)
	{
		aux = *s;
		while (aux->next->content != (*s)->content)
		{
			if ((aux->next->content - aux->content) * order < 0)
				return (0);
			aux = aux->next;
		}
	}
	return (1);
}

int	all_sorted(t_stack **a, t_stack **b)
{
	if (stack_sorted(a, 1) == 1)
	{
		if (stack_sorted(b, -1) == 1)
		{
			if (a && b && *a && *b)
			{
				if ((*a)->content > (*b)->content)
					return (1);
			}
			else
				return (1);
		}
	}
	return (0);
}

void	sort_original(t_stack **a, int n)
{
	if (stack_sorted(a, 1) != 1)
	{
		if (just_rotate(a, 1) == 1)
		{
			while (stack_sorted(a, 1) != 1)
				do_rotate(a, way_to_rotate(a, 1), 'a');
		}
		if (1 < n && n < 99)
			sort_stack(a);
		else
			radix_bin_sort(a, n);
	}
}
