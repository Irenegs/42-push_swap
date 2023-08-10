/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pintastack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:55:23 by irgonzal          #+#    #+#             */
/*   Updated: 2023/07/19 19:18:44 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

void pintastack(stack **lst)
{
    stack *aux;

    if (lst && *lst)
    {
        printf("Stack:\n");
        printf("%d\n", (*lst)->content);
        aux = (*lst)->next;
        while (aux != *lst)
        {
            printf("%d\n", aux->content);
            aux = aux->next;
        }
    }
    else
    {
        if (lst)
            printf("Vacio\n");
        else
            printf("No pointer\n");
    }
}

void pintainv(stack **lst)
{
    stack *aux;

    if (lst && *lst)
    {
        printf("StackInv:\n");
        printf("%d\n", (*lst)->prev->content);
        aux = (*lst)->prev->prev;
        while (aux != (*lst)->prev)
        {
            printf("%d\n", aux->content);
            aux = aux->prev;
        }
    }
    else
    {
        if (lst)
            printf("Vacio\n");
        else
            printf("No pointer\n");
    }
}