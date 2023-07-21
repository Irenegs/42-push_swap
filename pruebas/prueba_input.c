/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:02:38 by irgonzal          #+#    #+#             */
/*   Updated: 2023/07/19 19:20:40 by irgonzal         ###   ########.fr       */
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
        write(1, "Error!\n", 7);
        //liberar(a)???
        return (0);
    }
    write(1, "[OK]\n",6);
    pintastack(&a);
    pintainv(&a);
}