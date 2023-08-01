#include <stdio.h>

int main()
{
    for (int i = 0; i < 20;i++)
    {
        printf("i & 1:%d\n", i & 1);
        //printf("i:%d\ni>>1:%d\n(i>>1)& 1:%d\n\n", i, i>>1, ((i>>1) & 1));
    }
}
