#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ThongTinSinhVien
{
    char HoTen[30];
    char ten[30];
    char mssv[30];
    char sdt[30];
} TT;
//===========================================
// Xu ly xau va ten
char *CatTen(char str[])
{
    int index;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
            index = i;
    }
    return &str[index + 1];
}

char *XoaBuff(char *str)
{
    str[strlen(str) - 1] = '\0';
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            continue;
        }
        else
        {
            str[i + 1] = '\0';
            break;
        }
    }
    return str;
}
//===========================================
int DocFile(const char *filename, TT *List)
{
    FILE *f = fopen(filename, "r");
    int dem = 0;
    char s[30];
    TT tg;
    while (fgets(s, 30, f) != NULL)
    {
        if (strcmp(s, "$") == 0)
            break;
        strcpy(tg.HoTen, XoaBuff(s));
        strcpy(tg.ten, CatTen(tg.HoTen));
        fgets(s, 30, f);
        strcpy(tg.mssv, XoaBuff(s));
        fgets(s, 30, f);
        strcpy(tg.sdt, XoaBuff(s));
        List[dem] = tg;
        dem++;
    }
    fclose(f);
    return dem;
}
//=============================================
//Dung sap xep nhanh de sap xep theo mssv
void swap(TT *A, int i, int j)
{
    TT c = A[i];
    A[i] = A[j];
    A[j] = c;
}
int partition(TT *A, int L, int R, int indexPivot)
{
    TT pivot = A[indexPivot];
    // doi cho phan tu chot ve cuoi nua phai
    // swap(A[indexPivot], A[R]);
    swap(A, indexPivot, R);
    int storeIndex = L; // vi tri cuoi cung cua nua trai
    for (int i = L; i <= R - 1; i++)
    {
        if (strcmp(A[i].mssv, pivot.mssv) <= 0)
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
void quickSort(TT *A, int L, int R)
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
//===========================================
// Them thong tin sinh vien moi
void ThemSV(TT *List, int *size)
{
    TT newStud;
    int n;
    printf("Nhap so sinh vien muon them vao: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Sinh vien thu %d\n", i + 1);
        printf("Nhap Ho va Ten: ");
        fflush(stdin);
        gets(newStud.HoTen);
        printf("Nhap MSSV: ");
        fflush(stdin);
        gets(newStud.mssv);
        printf("Nhap SDT: ");
        fflush(stdin);
        gets(newStud.sdt);
        fflush(stdin);
        List[*size] = newStud;
        (*size)++;
    }

    quickSort(List, 0, *size - 1);
}
//======================================
// Ghi ra file Output.txt
void GhiFile(TT List[], int size, const char *FILENAME)
{
    FILE *f = fopen(FILENAME, "w+");
    for (int i = 0; i < size; i++)
    {
        fprintf(f, "%s\n%s\n%s\n", List[i].HoTen, List[i].mssv, List[i].sdt);
    }
    fprintf(f, "$");
    fclose(f);
}
//===========================================
// Tim kiem thong tin sinh vien theo mssv bang tim kiem nhi phan
void TimKiemNhiPhan(TT list[], int size, char target[])
{
    int L = 0, R = size - 1, Mid;
    printf("Ket qua tim kiem:\n");
    while (L <= R)
    {
        Mid = (L + R) / 2;
        if (strcmp(list[Mid].mssv, target) < 0)
            L = Mid + 1;
        if (strcmp(list[Mid].mssv, target) > 0)
            R = Mid - 1;
        if (strcmp(list[Mid].mssv, target) == 0)
        {
            printf("| %-15s | %-5s | %-10s | %-15s|\n","Ho va ten", "Ten", "MSSV", "SDT");
            printf("| %-15s | %-5s | %-10s | %-15s|\n",list[Mid].HoTen, list[Mid].ten, list[Mid].mssv, list[Mid].sdt);
            return;
        }
    }
    printf ("Khong tim thay!\n");
}
//===========================================
// In danh sach sinh vien hien co
void InDS(TT list[], int size)
{
    printf("|%-3s | %-15s | %-5s | %-10s | %-15s|\n", "STT", "Ho va ten", "Ten", "MSSV", "SDT");
    for (int i = 0; i < size; i++)
    {
        printf("|%-3d | %-15s | %-5s | %-10s | %-15s|\n", i + 1, list[i].HoTen, list[i].ten, list[i].mssv, list[i].sdt);
    }
    printf("\n");
}
//===========================================
int main()
{
    TT List[100];
    int size = DocFile("Input.txt", List);
    printf("Danh sach duoc doc tu FILE la:\n");
    InDS(List, size);
    quickSort(List, 0, size - 1);
    printf("Danh sach sau khi da sap xep: \n");
    InDS(List, size);
    /*
    ThemSV (List, &size);
    printf ("Danh sach moi: \n");
    InDS(List, size);
    GhiFile (List, size,"Output.txt");
    */
    char mssv[30];
    printf ("Nhap ma so sinh vien can tim: ");
    fflush (stdin);
    gets (mssv);
    fflush (stdin);
    TimKiemNhiPhan(List, size, mssv);
    return 0;
}