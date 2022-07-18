#include <stdio.h>
#include <stdlib.h>

void PrintArr(int *arr, int size);
//====================================================
// Doc dau vao tu FILE
void DocFile (const char *filename, int *M, int *n, int *arr)
{
    FILE *f=fopen(filename,"r");
    fscanf (f, "%d %d",&(*M),&(*n));
    for (int i=0; i<*n; i++)
    {
        fscanf (f,"%d ",&arr[i]);
    }
    fclose (f);
    printf ("Day doc vao tu FILE:\n");
    PrintArr (arr, *n);
}
//====================================================
// Sap xep nhanh day de tim kiem nhi phan
void swap(int *A, int i, int j)
{
    int c = A[i];
    A[i] = A[j];
    A[j] = c;
}
int partition(int A[], int L, int R, int indexPivot)
{
    int pivot = A[indexPivot];
    // doi cho phan tu chot ve cuoi nua phai
    // swap(A[indexPivot], A[R]);
    swap(A, indexPivot, R);
    int storeIndex = L; // vi tri cuoi cung cua nua trai
    for (int i = L; i <= R - 1; i++)
    {
        if (A[i] < pivot)
        { // swap(A[storeIndex], A[i]);
            swap(A, storeIndex, i);
            storeIndex++;
        }
    }
    // doi phan tu chot ve cuoi cua nua trai
    // swap(A[storeIndex], A[R]);
    swap(A, storeIndex, R);
    return storeIndex;
}
// chot la phan tu giua
void quickSort(int A[], int L, int R)
{
    if (L < R)
    {
        int index = (L + R) / 2;
        index = partition(A, L, R, index);
        if (L < index) // check xem co phan tu de goi de quy
            quickSort(A, L, index - 1);
        if (index < R)
            quickSort(A, index + 1, R);
    }
}
//====================================================
// Tim kiem nhi phan xem phan tu tu 1 den M da co trong day hay chua
// Neu co tim thay thi tra ve False con chua co thi tra ve True
bool TimKiemNhiPhan (int arr[], int target, int n)
{
    int L=0,R=n-1,Mid;
    while (L <= R)
    {
        Mid = (L+R)/2;
        if (target < arr[Mid])
            R = Mid-1;
        if (target > arr[Mid])
            L = Mid+1;
        if (target == arr[Mid])
        {
            return false;
        }
    }
    return true;
}

void TimKiemSoThieu (int arr[], int M, int n)
{
    printf ("Cac so bi thieu la: \n");
    for (int i=1; i<=M; i++)
    {
        if (TimKiemNhiPhan (arr, i, n))
            printf ("%d ",i);
    }
}
//====================================================
// Ham in day hien tai ra man hinh
void PrintArr (int *arr, int size)
{
    for (int i=0; i<size; i++)
    {
        printf ("%d ",arr[i]);
    }
    printf ("\n");
}
//====================================================

int main ()
{
    int arr[100];
    int M,n;
    DocFile ("Input_bai3.txt",&M,&n,arr);
    printf ("\n");

    quickSort (arr,0,n-1);
    printf ("Day da duoc sap xep:\n");
    PrintArr (arr, n);
    printf ("\n");

    TimKiemSoThieu (arr, M, n);
}