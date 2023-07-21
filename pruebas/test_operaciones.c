#include "push_swap.h"

void pruebas()
{
    stack *stack_1 = create_stack(1);
    stack *stack_2 = create_stack(2);
    stack *stack_3 = create_stack(3);
    stack *stack_4 = create_stack(4);
    stack *stack_5 = create_stack(5);
    stack *stack_6 = create_stack(6);

    add_stack(&stack_1, stack_2);
    add_stack(&stack_1, stack_3);
    add_stack(&stack_4, stack_5);
    add_stack(&stack_4, stack_6);
    
    
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
