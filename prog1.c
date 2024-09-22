#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number:");
    scanf("%d", &n);
    
    int *p = &n;
    int **pp = &p;

    printf("Number printed using pointer-%d\n", *p);
    printf("Number printed using pointer to pointer-%d\n", **pp);

    return 0;
}