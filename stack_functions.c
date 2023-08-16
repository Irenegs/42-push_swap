/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:41:40 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/16 17:36:38 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

stack	*create_node(int content)
{
	stack	*ptr;
	stack	aux;

	ptr = malloc(sizeof(stack));
	if (!ptr)
		return (NULL);
	aux.content = content;
	aux.next = ptr;
	aux.prev = ptr;
    *ptr = aux;
	return (ptr);
}

void    add_stack(stack **s, stack *new)
{
    if (s && *s)
    {
        new->next = *s;
        new->prev = (*s)->prev;
        ((*s)->prev)->next = new;
        (*s)->prev = new;
    }
    *s = new;
}

void    add_below(stack **s, stack *new)
{
    if (s && *s)
    {
        (*s)->prev->next = new;
        new->prev = (*s)->prev;
        (*s)->prev = new;
        new->next = *s;
    }
    else
        *s = new;
}

stack   *extract_node(stack **s)
{
    stack   *aux;

    if (!*s)
        return (NULL);
    aux = *s;
    if ((*s)->next == *s)
        *s = NULL;
    else
    {
        (*s)->prev->next = (*s)->next;
        (*s)->next->prev = (*s)->prev;
        *s = (*s)->next;
    }
    aux->next = aux;
    aux->prev = aux;
    return (aux);
}

void    clear_all_stack(stack **s)
{
    stack   *a;
    stack   *b;

    if (!s || !*s)
        return ;
    a = (*s)->next;
    b = a->next;
    (*s)->next = NULL;
    while (a->next)
    {
        free(a);
        a = b;
        b = a->next;
    }
}
