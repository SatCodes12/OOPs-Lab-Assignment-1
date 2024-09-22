#include <stdio.h>

int main()
{
    int n;
    printf("Enter size of array:");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("Elements printed using pointers\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", *(arr + i));
    }

    return 0;
}