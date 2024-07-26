
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define ARR_RANGE 5

void	handle_swap(int *arr)
{
	if (arr[0] == 0 || arr[1] == 0)
        return;
    int temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
    return;
}

void	handle_push(int *arr1, int *arr2)
{
    if (arr2[0] == 0)
    	return;
    arr1[0] = arr2[0];
    return;
}

void	handle_rotate(int *arr)
{
    int temp;
    int i = 0;
    while (i < (ARR_RANGE - 1))
    {
        temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        i++;
    }
    return;
}

void	handle_rev_rotate(int *arr)
{
    int temp;
    int i = ARR_RANGE - 1;
    while (i > 0)
	{
        temp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = temp;
        i--;
    }
    return;
}

int main(int argc, char *argv[])
{
    int* a = (int *)malloc(sizeof(int) * ARR_RANGE);
    int* b = (int *)malloc(sizeof(int) * ARR_RANGE);
	a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4 , a[4] = 5;
	int i = 1;
    while (i < argc)
    {
		if (strcmp(argv[i], "sa") == 0)
        	handle_swap(a);
        else if (strcmp(argv[i], "sb") == 0)
        	handle_swap(b);
        else if (strcmp(argv[i], "pa") == 0)
        	handle_push(a, b);
        else if (strcmp(argv[i], "pb") == 0)
        	handle_push(b, a);
        else if (strcmp(argv[i], "ra") == 0)
        	handle_rotate(a);
        else if (strcmp(argv[i], "rb") == 0)
        	handle_rotate(b);
        else if (strcmp(argv[i], "rra") == 0)
        	handle_rev_rotate(a);
        else if (strcmp(argv[i], "rrb") == 0)
        	handle_rev_rotate(b);
		i++;
    }
    printf(" ----- a stack ----- \n");
	for (int i = 0; i < 5; i++)
    	printf("|%d|", a[i]);
	printf("\n ----- b stack ----- \n");
    for (int i = 0; i < 5; i++)
    	printf("|%d|", b[i]);
    printf("\n");
    free(a);
    free(b);
    return (0);
}