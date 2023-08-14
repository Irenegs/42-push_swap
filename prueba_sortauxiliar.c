
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
    sort_auxiliar(NULL, &a);
}