/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:57:12 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/22 19:42:38 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

void	swap(t_stack **lst)
{
	int	aux;

	if (lst && *lst)
	{
		aux = (*lst)->content;
		(*lst)->content = (*lst)->next->content;
		(*lst)->next->content = aux;
	}
}

void	rotate(t_stack **lst, int way)
{
	if (lst && *lst)
	{
		if (way > 0)
			*lst = (*lst)->next;
		else
			*lst = (*lst)->prev;
	}
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*aux;

	if (!src || !*src)
		return ;
	aux = extract_node(src);
	add_stack(dst, aux);
}

void	swap_both(t_stack **st_a, t_stack **st_b)
{
	swap(st_a);
	swap(st_b);
}

void	rotate_both(t_stack **st_a, t_stack **st_b, int way)
{
	rotate(st_a, way);
	rotate(st_b, way);
}
