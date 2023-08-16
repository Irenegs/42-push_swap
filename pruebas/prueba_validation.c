/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:02:38 by irgonzal          #+#    #+#             */
/*   Updated: 2023/08/16 18:19:49 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int *numb;

    if (argc == 1)
        exit (0);
    //printf("argc:%d\n", argc);
    numb = validate_input_normal(argc, argv);
    if (!numb)
    {
        write(1, "Error!\n", 7);
        return (0);
    }
    for (int i = 0; i < argc - 1; i++)
        //printf("\nValue:%d:\n",numb[i]);
    write(1, "[OK]\n",6);
}