/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_enteros.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:02:38 by irgonzal          #+#    #+#             */
/*   Updated: 2023/07/19 19:08:09 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc == 1)
        exit (0);
    for (int i = 1; i < argc; i++)
    {
        if (arg_isint(argv[i], ft_atoi(argv[i])) != 0)
        {
            write(1, "Error!\n", 7);
            return (0);
        }
    }
    write(1, "[OK]\n",6);
}