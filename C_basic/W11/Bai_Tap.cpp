#include <stdio.h>
void selectionSort(int *a, int n)
{
    int i, j, tmp, vtMax; // vi tri phan tu lon nhat trong day hien tai
    for (i = n; i > 1; i--)
    {
        vtMax = 0;
        for (j = 1; j < i; j++)
            if (a[j] > a[vtMax])
                vtMax = j; // doi cho phan tu lon nhat trong day voi phan tu cuoi
        tmp = a[i - 1];
        a[i - 1] = a[vtMax];
        a[vtMax] = tmp;
    }
}

void inMang (int *arr, int n)
{
    for (int i = 0; i<n; i++)
    {
        printf ("%d ",arr[i]);
    }
    printf ("\n");
}

void cau4(int *arr, int n, int k)
{
    printf ("Cau 4:\n");
    printf ("Phan tu lon nhat thu %d: %d",k,arr[n-k]);
}

void cau3 (int *arr, int n)
{
    printf ("Cau 3:\n");
    int tmp=arr[1];
    int f=1;
    for (int i=1; i<n; i++)
    {
        if (arr[i]==tmp)
            f++;
        else 
        {
            printf ("%d : %d\n",tmp,f);
            f=1;
            tmp = arr[i];
        }
        if (i==n-1)
            printf ("%d : %d\n",tmp,f);
    }
}

void cau2 (int *arr, int n, int k)
{
    printf ("Cau 2:\n");
    for (int i=0; i<n/2; i++)
    {
        for (int j=n-1; j>i; j--)
        {
            if (arr[i]+arr[j] == k)
                printf ("a=%d,b=%d\n",arr[i],arr[j]);
        }
    }
}

void cau1 (int *arr, int n)
{
    printf ("Cau 1:\n");
    int tmp=arr[0];
    printf ("%d ",tmp);
    for (int i=0; i<n; i++)
    {
        if (arr[i] == tmp)
            continue;
        printf ("%d ",arr[i]);
        tmp = arr[i];
    }
    printf ("\n");
}

int main()
{
    int arr4[] = {1,1,2,4,5,3,4,6,7,7,6};
    int n=sizeof(arr4)/4;
    selectionSort (arr4,n);
    printf ("Mang sau khi sap xep:\n");
    inMang (arr4,n);
    cau1(arr4,n);
    int arr[] = {1,2,4,5,3};
    int n2=sizeof(arr)/4;
    cau2 (arr, n2, 3);
    cau3(arr4,n);
    cau4 (arr4, n, 1);
}





