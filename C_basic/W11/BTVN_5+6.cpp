#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ThongTin
{
    char Tu[50];
    int tanSo;
}TT;

void XuLyDau (char str[])
{
    for (int i = strlen(str)-1; i>=0; i--)
    {
        if (str[i] == ',')
            str[i] = ' ';
        if (str[i] == '.')
            str[i] = ' ';
        if (str[i] == '!')
            str[i] = ' ';
        if (str[i] == '\n')
            str[i] = ' ';
    }
}

void TachTuDauTien (char* str)
{
    int i=0;
    // loại bỏ dấu cách trống đầu 
    while(i<strlen(str) && str[i]==' ') i++;
    if(i==strlen(str))
        strcpy(str,"");
    else
    {
        //và cuối
        strcpy(str,&str[i]);
        int j=1;
        while(j<strlen(str) && str[j]!=' ') j++;
        if(j<strlen(str)) str[j]='\0';
    }
}

void SapXep (char list[][50], int dem)
{
    char tmp[50];
    for (int i=dem-1; i>=0; i--)
    {
        for (int j=0; j<i; j++)
        {
            if (strcmp(list[j],list[i])>0)
            {
                strcpy (tmp,list[i]);
                strcpy (list[i],list[j]);
                strcpy (list[j],tmp);
            }
        }
    }
    
}




int tach_tu (char str[], char list[][50], int dem)
{
    char tmp[500];
    strcpy (tmp, str);
    //printf ("%s", tmp);
    TachTuDauTien (&tmp[0]);
    strcpy (list[dem],&tmp[0]);
    dem++;
    for (int i=0; i<strlen(str); i++)
    {
        if (str[i] != ' ' && str[i-1] == ' ')
        {
            TachTuDauTien (&tmp[i]);
            strcpy (list[dem],&tmp[i]);
            dem++;
        }
    }
    return dem;
}
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
void CacTuKhongTrung (char list[][50], int dem, TT thongTin[])
{
    int count = 0, tanso = 1;
    strcpy (thongTin[count].Tu,list[0]);
    for (int i=1; i<dem; i++)
    {
        if (strcmp(list[i],thongTin[count].Tu) == 0)
        {
            tanso++;
            continue;
        }
        thongTin[count].tanSo = tanso;
        count++;
        tanso = 1;
        strcpy (thongTin[count].Tu,list[i]);
    }
    strcpy (thongTin[count].Tu,list[dem-1]);
    for (int i=0; i<count-1; i++)
    {
        printf ("%d - %s:%d\n",i,thongTin[i].Tu,thongTin[i].tanSo);
    }
}

int main ()
{
    FILE* f = fopen ("FileInput.txt","r+");
    char str[500];
    char tmp[500];
    fflush (stdin);
    while (fgets (tmp,500,f) != NULL)
    {
        strcat (str,tmp);
    }
    fclose (f);
    XuLyDau (str);
    char list[100][50];
    int dem = 0;
    dem = tach_tu (str, list, dem);
    printf ("\n");
    SapXep (list,dem);
    TT thongTin[dem];
    CacTuKhongTrung (list,dem,thongTin);
    return 0;
}
