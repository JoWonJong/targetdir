#include <stdio.h>
int ascending(const void *a, const void *b)
{
    if(*(int *)a > *(int *)b)
        return 1;
    else if(*(int *)a < *(int *)b)
        return -1;
    else
        return 0;
}

int descending(const void *a, const void *b)
{
    if(*(int *)a < *(int *)b)
        return 1;
    else if(*(int *)a > *(int *)b)
        return -1;
    else
        return 0;
}

void output(int data[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}