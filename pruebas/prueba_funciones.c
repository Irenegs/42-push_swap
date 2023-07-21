/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_funciones.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:26:09 by irgonzal          #+#    #+#             */
/*   Updated: 2023/07/01 18:19:07 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pruebas()
{
    stack *stack_a = create_node(1);
    stack *stack_b = create_node(2);
    stack *stack_c = create_node(3);

    add_below(&stack_a, stack_b);
    pintastack(&stack_a);
    pintainv(&stack_a);
    printf("orden %d\n", stack_sorted(&stack_a));
    stack *stack_d = extract_node(&stack_a);
    stack *stack_e = extract_node(&stack_a);
    printf("Vacio: %p", stack_a);

    add_stack(&stack_a, stack_c);
    pintastack(&stack_a);
    pintainv(&stack_a);

    stack *stack_f = extract_node(&stack_a);
    pintastack(&stack_a);
    pintainv(&stack_a);
    pintastack(&stack_d);
    pintastack(&stack_e);
    pintastack(&stack_f);
    //free(stack_d);
    //clear_stack(&stack_a);    
}

void runleaks(void)
{
    system("leaks push_swap");
}

int main(void)
{
    pruebas();
    atexit(runleaks);
}
