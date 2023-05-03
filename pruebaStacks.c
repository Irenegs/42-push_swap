/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebaStacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:26:09 by irgonzal          #+#    #+#             */
/*   Updated: 2023/05/03 18:48:58 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pruebas()
{
    stack *stack_a = create_stack(3);
    stack *stack_b = create_stack(2);
    stack *stack_c = create_stack(1);

    add_stack(&stack_a, stack_b);
    printf("\n[%d,%d,%d]\n", stack_a->content, stack_a->next->content, stack_a->prev->content);

    add_stack(&stack_a, stack_c);
    printf("\n[%d,%d,%d,%d]\n", stack_a->content, stack_a->next->content, stack_a->next->next->content, stack_a->prev->content);

    
    stack *stack_d = malloc(1*sizeof(stack));
    stack_d = extract_stack(&stack_a);
    printf("\n[%d,%d,%d,%d]\n", stack_a->content, stack_a->next->content, stack_a->next->next->content, stack_d->content);
    
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
