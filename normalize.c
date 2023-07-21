/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:13:39 by irgonzal          #+#    #+#             */
/*   Updated: 2023/07/18 18:14:20 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

int value_isunique(int value, stack **lst)
{
    stack *aux;
    
    if (*lst)
    {
        if (value == (*lst)->content)
            return (0);
        aux = (*lst)->next;
        while (aux != *lst)
        {
            if (value == aux->content)
                return (0);
            aux = aux->next;
        }
    }
    return (1);
}

int arg_isint(char *arg, int value)
{
    if (ft_strncmp(ft_itoa(value), arg, 12) != 0)
        return (0);
    return (1);
}

int validate_input(int n, char **arg, stack **numbers)
{
    int     i;
    int     value;
    stack   *current;
    stack   *lst;

    i = 0;
    while (i + 1 < n)
    {
        value = ft_atoi(arg[i + 1]);
        if (arg_isint(arg[i + 1], value) == 1 && value_isunique(value, lst) == 1)
        {
            current = create_node(value);
            add_number(lst, current);
        }
        else
            return (1);
        i++;
    }
    return (0);
}