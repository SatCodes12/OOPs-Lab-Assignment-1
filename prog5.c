#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

char **allocateMemory_names(int n)
{
    char **names = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        names[i] = (char *)malloc(MAX_LENGTH * sizeof(char));
    }
    return names;
}

int *allocateMemory_ages(int n)
{
    int *ages = (int *)malloc(n * sizeof(int));
    return ages;
}

void sortbyAge(char **names, int *ages, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ages[j] > ages[j + 1])
            {
                int temp = ages[j];
                ages[j] = ages[j + 1];
                ages[j + 1] = temp;

                char dummy[MAX_LENGTH];
                strcpy(dummy, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], dummy);
            }
        }
    }
}

void printDetails(char **names, int *ages, int n)
{
    printf("Name\tAge\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t%d\n", names[i], ages[i]);
    }
}

int main()
{
    int n;
    printf("Enter number of persons:");
    scanf("%d", &n);

    int *ages = allocateMemory_ages(n);
    char **names = allocateMemory_names(n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter details of person-%d\n", i + 1);
        printf("Enter name: ");
        scanf("%s", names[i]);
        printf("Enter age: ");
        scanf("%d", &ages[i]);
    }

    sortbyAge(names, ages, n);
    printDetails(names, ages, n);
    
    return 0;
}