#include <stdio.h>
#include <stdlib.h>

int getDimension()
{
	int n;
	printf("Enter the size of array: ");
	scanf("%d", &n);

	return n;
}

int *allocateMemory(int n)
{
	int *arr = (int *)malloc(n * sizeof(int));
	return arr;
}

void inputValues(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Enter element %d: ", i + 1);
		scanf("%d", arr + i);
	}
}

void display(int *arr, int n)
{
	printf("You entered array: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(arr + i));
	}
}

int main()
{
	int n = getDimension();
	int *arr = allocateMemory(n);
	inputValues(arr, n);
	display(arr, n);

	return 0;
}