#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

typedef struct{
    char name[MAX_LENGTH];
    int age;
} Person;

Person *allocateMemory(int n)
{
    Person *records = (Person *)malloc(n * sizeof(Person));
    return records;
}

void sortbyAge(Person *records, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (records[j].age > records[j + 1].age)
            {
                Person temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

void printDetails(Person *records, int n)
{
    printf("Name\tAge\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t%d\n", records[i].name, records[i].age);
    }
}

int main()
{
    int n;
    printf("Enter number of persons:");
    scanf("%d", &n);

    Person *records = allocateMemory(n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter details of Person-%d\n", i + 1);
        printf("Enter name: ");
        scanf("%s", records[i].name);
        printf("Enter age: ");
        scanf("%d", &records[i].age);
    }

    sortbyAge(records, n);
    printDetails(records, n);

    return 0;
}