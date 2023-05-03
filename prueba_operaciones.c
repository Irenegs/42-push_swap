/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_operaciones.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:46:50 by irgonzal          #+#    #+#             */
/*   Updated: 2023/05/03 20:09:39 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pruebas()
{
    stack *stack_1 = create_stack(1);
    stack *stack_2 = create_stack(2);
    stack *stack_3 = create_stack(3);
    stack *stack_4 = create_stack(4);
    stack *stack_5 = create_stack(5);
    stack *stack_6 = create_stack(6);
    stack *stack_7 = create_stack(7);
    
    add_stack(&stack_1, stack_2);
    add_stack(&stack_1, stack_3);
    add_stack(&stack_1, stack_4);
    add_stack(&stack_5, stack_6);
    add_stack(&stack_5, stack_7);
    
    printf("\n[Inicio]\n");
    printf("\n[%d,%d,%d]\n", stack_1->content, stack_1->next->content, stack_1->prev->content);
    printf("\n[%d,%d,%d]\n", stack_5->content, stack_5->next->content, stack_5->prev->content);
/*    
    printf("\n[swap]\n");
    swap(&stack_1);
    printf("\n[Inic:%d,%d,%d]\n", stack_1->content, stack_1->next->content, stack_1->prev->content);
    printf("\n[Next:%d,%d,%d]\n", stack_1->next->content, stack_1->next->next->content, stack_1->next->prev->content);
    printf("\n[Prev:%d,%d,%d]\n", stack_1->prev->content, stack_1->prev->next->content, stack_1->prev->prev->content);
*/
/*
    printf("\n[rotate]\n");
    rotate(&stack_1,1);
    printf("\n[%d,%d,%d]\n", stack_1->content, stack_1->next->content, stack_1->prev->content);
    rotate(&stack_1, -1);
    printf("\n[%d,%d,%d]\n", stack_1->content, stack_1->next->content, stack_1->prev->content);
*/

    printf("\n[push x 3]\n");
    push(&stack_1, &stack_5);
    printf("\n[%d,%d,%d]\n", stack_1->content, stack_1->next->content, stack_1->prev->content);
    printf("\n[%d,%d,%d]\n", stack_5->content, stack_5->next->content, stack_5->prev->content);
    push(&stack_1, &stack_5);
    printf("\n[%d,%d,%d]\n", stack_1->content, stack_1->next->content, stack_1->prev->content);
    printf("\n[%d,%d,%d]\n", stack_5->content, stack_5->next->content, stack_5->prev->content);
    push(&stack_1, &stack_5);
    printf("\n[%d,%d,%d]\n", stack_1->content, stack_1->next->content, stack_1->prev->content);
    printf("\n[%d,%d,%d]\n", stack_5->content, stack_5->next->content, stack_5->prev->content);
    push(&stack_1, &stack_5);
    if (stack_1)
        printf("\n[%d,%d,%d]\n", stack_1->content, stack_1->next->content, stack_1->prev->content);
    else
        printf("\n[Vacio]\n");
    printf("\n[%d,%d,%d]\n", stack_5->content, stack_5->next->content, stack_5->prev->content);
    
    push(&stack_5, &stack_1);
    printf("\n[%d,%d,%d]\n", stack_1->content, stack_1->next->content, stack_1->prev->content);
    printf("\n[%d,%d,%d]\n", stack_5->content, stack_5->next->content, stack_5->prev->content);
    push(&stack_5, &stack_1);
    printf("\n[%d,%d,%d]\n", stack_1->content, stack_1->next->content, stack_1->prev->content);
    printf("\n[%d,%d,%d]\n", stack_5->content, stack_5->next->content, stack_5->prev->content);
    push(&stack_5, &stack_1);
    printf("\n[%d,%d,%d]\n", stack_1->content, stack_1->next->content, stack_1->prev->content);
    printf("\n[%d,%d,%d]\n", stack_5->content, stack_5->next->content, stack_5->prev->content);
    
    printf("\nBoth: rotate + swap\n");
    rotate_both(&stack_5, &stack_1,1);
    swap_both(&stack_5, &stack_1);
    printf("\n[%d,%d,%d]\n", stack_1->content, stack_1->next->content, stack_1->prev->content);
    printf("\n[%d,%d,%d]\n", stack_5->content, stack_5->next->content, stack_5->prev->content);
    
}

void runleaks(void)
{
    system("leaks -q push_swap");
}

int main(void)
{
    pruebas();
    atexit(runleaks);
}
