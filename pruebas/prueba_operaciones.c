/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_operaciones.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:46:50 by irgonzal          #+#    #+#             */
/*   Updated: 2023/07/01 17:58:49 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pruebas()
{
    stack *stack_1 = create_node(1);
    stack *stack_2 = create_node(2);
    stack *stack_3 = create_node(3);
    stack *stack_4 = create_node(4);
    stack *stack_5 = create_node(5);
    stack *stack_6 = create_node(6);
    

    //stack_7 = malloc(sizeof(stack));
    
    add_stack(&stack_1, stack_2);
    add_stack(&stack_1, stack_3);
    add_stack(&stack_1, stack_4);
    add_stack(&stack_5, stack_6);
    
    printf("\n[Inicio]\n");
    pintastack(&stack_1);
    pintainv(&stack_1);
    //pintastack(&stack_5);
    //pintainv(&stack_5);
/*    
    printf("\n[swap]\n");
    swap(&stack_1);
    pintastack(&stack_1);
    pintainv(&stack_1);
*/
/*
    do_swap(&stack_1, '1');
    pintastack(&stack_1);
    pintainv(&stack_1);
*/
/*
    printf("\n[rotate]\n");
    rotate(&stack_1,1);
    pintastack(&stack_1);
    pintainv(&stack_1);
    rotate(&stack_1, -1);
    pintastack(&stack_1);
    pintainv(&stack_1);
*/
/*
    do_rotate(&stack_1,1, '1');
    pintastack(&stack_1);
    pintainv(&stack_1);
    do_rotate(&stack_1, -1, '1');
    pintastack(&stack_1);
    pintainv(&stack_1);
*/
/*
    printf("\n[push x 3]\n");
    push(&stack_1, &stack_5);
    pintastack(&stack_1);
    pintainv(&stack_1);
    pintastack(&stack_5);
    pintainv(&stack_5);
    push(&stack_1, &stack_5);
        pintastack(&stack_1);
    pintainv(&stack_1);
    pintastack(&stack_5);
    pintainv(&stack_5);
    push(&stack_1, &stack_5);
    pintastack(&stack_1);
    pintainv(&stack_1);
    pintastack(&stack_5);
    pintainv(&stack_5);
    push(&stack_1, &stack_5);
    if (stack_1)
        printf("\n[%d,%d,%d]\n", stack_1->content, stack_1->next->content, stack_1->prev->content);
    else
        printf("\n[Vacio]\n");
    printf("\n[%d,%d,%d]\n", stack_5->content, stack_5->next->content, stack_5->prev->content);
*/
    stack *stack_7 = create_node(7);
    extract_node(&stack_7);
    printf("\n[%p %p]\n", &stack_7, stack_7);
    do_push(&stack_1, &stack_7, '7');
    pintastack(&stack_1);
    pintainv(&stack_1);
    pintastack(&stack_7);
/*
    pintainv(&stack_5);
    do_push(&stack_1, &stack_5, '5');
    pintastack(&stack_1);
    pintainv(&stack_1);
    pintastack(&stack_5);
    pintainv(&stack_5);
    do_push(&stack_1, &stack_5, '5');
    pintastack(&stack_1);
    pintainv(&stack_1);
    pintastack(&stack_5);
    pintainv(&stack_5);
    do_push(&stack_1, &stack_5, '5');
    if (stack_1)
        printf("\n[%d,%d,%d]\n", stack_1->content, stack_1->next->content, stack_1->prev->content);
    else
        printf("\n[Vacio]\n");
    printf("\n[%d,%d,%d]\n", stack_5->content, stack_5->next->content, stack_5->prev->content);
*/
/*    
    push(&stack_5, &stack_1);
    pintastack(&stack_1);
    pintainv(&stack_1);
    pintastack(&stack_5);
    pintainv(&stack_5);
    push(&stack_5, &stack_1);
    pintastack(&stack_1);
    pintainv(&stack_1);
    pintastack(&stack_5);
    pintainv(&stack_5);
    push(&stack_5, &stack_1);
    pintastack(&stack_1);
    pintainv(&stack_1);
    pintastack(&stack_5);
    pintainv(&stack_5);
*/
/*
    do_push(&stack_5, &stack_1, '1');
    pintastack(&stack_1);
    pintainv(&stack_1);
    pintastack(&stack_5);
    pintainv(&stack_5);
    do_push(&stack_5, &stack_1, '1');
    pintastack(&stack_1);
    pintainv(&stack_1);
    pintastack(&stack_5);
    pintainv(&stack_5);
    do_push(&stack_5, &stack_1, '1');
    pintastack(&stack_1);
    pintainv(&stack_1);
    pintastack(&stack_5);
    pintainv(&stack_5);
*/
/*    
    printf("\nBoth: rotate + swap\n");
    rotate_both(&stack_5, &stack_1,1);
    swap_both(&stack_5, &stack_1);
    pintastack(&stack_1);
    pintainv(&stack_1);
    pintastack(&stack_5);
    pintainv(&stack_5);
*/
/*
    do_rotate_both(&stack_5, &stack_1,-1);
    do_swap_both(&stack_5, &stack_1);
    pintastack(&stack_1);
    pintainv(&stack_1);
    pintastack(&stack_5);
    pintainv(&stack_5);
*/
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
