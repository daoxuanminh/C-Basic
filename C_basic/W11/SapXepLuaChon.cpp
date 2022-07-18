#include <stdio.h>

void inDS (int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf ("%d ",arr[i]);
    }
    printf ("\n");
} 

void SapXepLuaChon (int arr[], int n)
{
    int tmp;
    for (int i = n-1; i>=0; i--)
    {
        for (int j=0; j<i; j++)
        {
            if (arr[j] > arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main ()
{
    int arr[] = {1,2,7,6,5,8,4};
    int n = sizeof(arr)/4;
    SapXepLuaChon (arr, n);
    inDS (arr, n);
}