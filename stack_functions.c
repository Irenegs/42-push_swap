/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:41:40 by irgonzal          #+#    #+#             */
/*   Updated: 2023/07/27 18:57:17 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

stack	*create_node(int content)
{
	stack	*ptr;
	stack	a;

	ptr = malloc(sizeof(stack));
	if (!ptr)
		return (NULL);
	a.content = content;
	a.next = ptr;
	a.prev = ptr;
    *ptr = a;
	return (ptr);
}

void    add_stack(stack **lst, stack *new)
{
    if (lst && *lst)
    {
        new->next = *lst;
        new->prev = (*lst)->prev;
        ((*lst)->prev)->next = new;
        (*lst)->prev = new;
    }
    *lst = new;
}

void    add_below(stack **lst, stack *new)
{
    if (lst && *lst)
    {
        (*lst)->prev->next = new;
        new->prev =(*lst)->prev;
        (*lst)->prev = new;
        new->next = *lst;
    }
    else
        *lst = new;
}

stack   *extract_node(stack **lst)
{
    stack   *aux;

    if (!*lst)
        return (NULL);
    aux = *lst;
    if ((*lst)->next == *lst)
        *lst = NULL;
    else
    {
        (*lst)->prev->next = (*lst)->next;
        (*lst)->next->prev = (*lst)->prev;
        *lst = (*lst)->next;
    }
    aux->next = aux;
    aux->prev = aux;
    return (aux);
}

void    clear_stack(stack *s)
{
    s->next = NULL;
    free(s);
}

void    clear_all_stack(stack **lst)
{
    stack   *a;
    stack   *b;

    if (!lst || !*lst)
        return ;
    a = *lst;
    b = a->next;
    while (b != *lst)
    {
        a = b;
        b = a->next;
        clear_stack(b);
    }
    clear_stack(*lst);
    *lst = NULL;
}

int stack_sorted(stack **lst)
{
    stack   *aux;
    
    if (lst && *lst)
    {
        aux = *lst;
        while (aux->next->content != (*lst)->content)
        {
            if (aux->content + 1 != aux->next->content)
                return (0);
            aux = aux->next;
        }
    }
    return (1);
}


int stack_rev_sorted(stack **lst)
{
    stack   *aux;
    
    if (lst && *lst)
    {
        aux = *lst;
        while (aux->next->content != (*lst)->content)
        {
            if (aux->content != aux->next->content + 1)
                return (0);
            aux = aux->next;
        }
    }
    return (1);
}