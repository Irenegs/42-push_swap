/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:40:49 by irgonzal          #+#    #+#             */
/*   Updated: 2023/07/20 18:17:39 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#	include "push_swap.h"

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

    if (stack_sorted(orig) == 1)
        return ;
    aux = extract_node(orig);
    write(1, "pb\n", 3);
    while (stack_sorted(orig) != 1 || (*orig)->content < aux->content)
    {
        do_push(orig, &aux, 'b');
        sort_auxiliar(orig, &aux);
    }
    all_back(orig, &aux);
}