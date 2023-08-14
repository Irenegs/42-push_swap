/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:47:22 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/14 18:53:13 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

int main(int argc, char **argv)
{
    stack   *a;
    
    if (argc == 1)
        exit (0);
    a = NULL;
    if (lst2stack(argc, argv, &a) == 1)
    {
        write(1, "Error\n", 6);
        return (0);
    }
    sort_original(&a, argc - 1);
    clear_all_stack(&a);
}