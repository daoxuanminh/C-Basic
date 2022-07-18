#include <stdio.h>

void swap (int *arr, int i, int j)
{
    int tg = arr[i];
    arr[i] = arr[j];
    arr[j] = tg;
}
void printArr (int *arr)
{
    for (int i=0; i<5; i++)
    {
        printf ("%d ",arr[i]);
    }
}

int main ()
{
    int arr[] = {1,2,3,4,5};
    swap (arr, 1, 2);
    printArr (arr);
}