#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* // Cho C++
void swap(int& a, int &b)
{
    int c = a;
    a=b;
    b=c;
}
*/
// cho C
// hoan doi gia tri 2 phan tu o vi tri i va j trong mang A


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
void printArr(int *A, int size)
{
    printf("Day hien tai:\n");
    for (int i = 0; i < size; i++)
        printf("%d, ", A[i]);
    printf("\n");
}


int main()
{
    int A[] = {1, 4, 6, 78, 23};
    int size = 5;
    printArr(A, size);
    quickSort(A, 0, size - 1);
    printArr(A, size);
    return 0;
}
