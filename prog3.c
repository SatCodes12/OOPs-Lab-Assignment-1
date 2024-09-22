
#include <stdio.h>
#include <stdlib.h>

void arrayOfPointers(int row, int col)
{

	int *arr[row];
	// taking input
	for (int i = 0; i < row; i++)
	{
		*(arr + i) = (int *)malloc(col * sizeof(int));
		for (int j = 0; j < col; j++)
		{
			scanf("%d", *(arr + i) + j);
		}
	}

	// output
	printf("\n2D Array:\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}
	printf("\n");

	return;
}

void pointerToPointerTwoMalloc(int row, int col)
{
	int **arr;
	arr = (int **)malloc(row * sizeof(int *));

	// input
	for (int i = 0; i < row; i++)
	{
		*(arr + i) = (int *)malloc(col * sizeof(int));
		for (int j = 0; j < col; j++)
		{
			scanf("%d", *(arr + i) + j);
		}
	}

	// output
	printf("\n2D Array:\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void pointerToPointerOneMalloc(int row, int col)
{
	int **arr;
	arr = (int **)malloc(row * sizeof(int *) + row * col * sizeof(int));

	// input
	for (int i = 0; i < row; i++)
	{
		arr[i] = arr[0] + (i + 1) * col;
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%d", *(arr + i) + j);
		}
	}

	// output
	printf("\n2D array\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void pointerToArray(int row, int col)
{
	int(*arr)[col] = malloc(row * sizeof(int[col]));

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	printf("\n2D Array:\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

int main()
{
	int row, col;
	printf("Enter row and columns of the 2D Array: ");
	scanf("%d %d", &row, &col);

	printf("Running function 1...\n");
	arrayOfPointers(row, col);

	printf("Running function 2...\n");
	pointerToPointerTwoMalloc(row, col);

	printf("Running function 3...\n");
	pointerToPointerOneMalloc(row, col);

	printf("Running function 4...\n");
	pointerToArray(row, col);
}