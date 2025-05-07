#include <stdio.h>

int main(void)
{
    int a[3] = {1, 2, 3};
    int* p;

    p = a;

    printf("a[0] = %d, a[1] = %d, a[2] = %d\n", *p, *(p+1), *(p+2));
    return 0;
}