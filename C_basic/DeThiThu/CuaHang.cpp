#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct CuaHang
{
    char ten;
    char monHang[100];
} Node;
int dem = 0;

void Sort(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = i + 1; j < strlen(str); j++)
        {
            if (str[i] > str[j])
            {
                char tg = str[i];
                str[i] = str[j];
                str[j] = tg;
            }
        }
    }
}

void SapXepMonHang(Node arr[])
{
    for (int i = 0; i < dem; i++)
    {
        Sort(arr[i].monHang);
    }
}

void LoadFile(const char *filename, Node Arr[])
{
    int n, count;
    char str[100];
    FILE *f = fopen(filename, "r");
    fscanf(f, "%d\n", &n);
    while (!feof(f))
    {
        count = 0;
        fgets(str, 50, f);
        Arr[dem].ten = str[0];
        for (int i = 1; i < strlen(str); i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                Arr[dem].monHang[count] = str[i];
                Arr[dem].monHang[count + 1] = '\0';
                ++count;
            }
        }
        dem++;
    }
    SapXepMonHang(Arr);
    fclose(f);
}

void PrintList(Node arr[])
{
    printf("%d\n", dem);
    for (int i = 0; i < dem; i++)
    {
        printf("%c\t", arr[i].ten);
        for (int j = 0; j < strlen(arr[i].monHang); j++)
        {
            printf("%c", arr[i].monHang[j]);
            if (arr[i].monHang[j + 1] != '\0')
                printf(",");
        }
        printf("\n");
    }
}

int TimKiem(char ten, Node arr[])
{
    for (int i = 0; i < dem; i++)
    {
        if (arr[i].ten == ten)
            return i;
    }
    return -1;
}

void XoaMonHang(Node arr[])
{
    printf("Chuc nang xoa!\n");
    char keyName, keyMatHang;
    printf("Nhap ten cua hang(1->5): ");
    scanf("%c", &keyName);
    fflush(stdin);
    if (keyName < '1' || keyName > '5')
    {
        printf("Khong ton tai cua hang!\n");
        return;
    }
    lai:
    printf("Nhap ten mat hang muon xoa: ");
    scanf("%c", &keyMatHang);
    fflush(stdin);
    if (keyMatHang == 'Q')
        return;
    int tmp = TimKiem(keyName, arr);
    for (int i = 0; i < strlen(arr[tmp].monHang); i++)
    {
        if (arr[tmp].monHang[i] == keyMatHang)
        {
            for (int j = i; j < strlen(arr[tmp].monHang); j++)
            {
                arr[tmp].monHang[j] = arr[tmp].monHang[j + 1];
            }
            printf("Da xoa thanh cong!\n");
            goto lai;
        }
    }
    printf("Khong co mat hang muon xoa!\n");
    goto lai;
}

void ThongTinCuaHang(Node arr[])
{
    printf("Tim thong tin mat hang trong cua hang(1->5): ");
    char keyTen;
    scanf("%c", &keyTen);
    fflush(stdin);
    int tmp = TimKiem(keyTen, arr);
    if (tmp == -1)
    {
        printf("Khong co cua hang nay!\n");
        return;
    }
    printf("%c\t", arr[tmp].ten);
    for (int j = 0; j < strlen(arr[tmp].monHang); j++)
    {
        printf("%c", arr[tmp].monHang[j]);
        if (arr[tmp].monHang[j + 1] != '\0')
            printf(",");
    }
    printf("\n");
}

int checkMatHang(Node arr[], char mathang)
{
    for (int i = 0; i < dem; i++)
    {
        for (int j = 0; j < strlen(arr[i].monHang); j++)
        {
            if (arr[i].monHang[j] == mathang)
                return j;
        }
    }
    return -1;
}

void ThemCuaHang(Node arr[])
{
    printf("Nhap ten cua hang muon them: ");
    char ten;
    int tmp = 0;
    scanf("%c", &ten);
    fflush(stdin);
    if (TimKiem(ten, arr) != -1)
    {
        printf("Cua hang da ton tai!\n");
        return;
    }
    arr[dem].ten = ten;
    char matHang;
    char choice;
    int count;
    printf("Nhap so mat hang muon them: ");
    scanf("%d", &count);
    fflush (stdin);
    for (int i = 0; i < count; i++)
    {
        printf("Nhap mat hang muon them: ");
        scanf("%c", &matHang);
        fflush(stdin);
        if (checkMatHang(arr, matHang) != -1)
        {
            arr[dem].monHang[tmp] = matHang;
            arr[dem].monHang[tmp + 1] = '\0';
            tmp++;
            printf ("Da them!\n");
        }
        else
        {
            printf ("Khong co mat hang nay trong cac cua hang khac!\n");
        }
    }
    dem++;
    SapXepMonHang (arr);
}

void Menu(Node Arr[])
{
    LoadFile("Input.txt", Arr);
    PrintList(Arr);
    char n;
    while (1)
    {
        printf("\n====Ban hay nhap chuc nang can thuc hien====\n");
        printf("*  1. Xac dinh cac mon hang trong cua hang\n");
        printf("*  2. Xoa di cac mon hang trong 1 cua hang\n");
        printf("*  3. Them 1 cua hang va cac mon hang trong do\n");
        printf("*  4. Tinh toan chi phi di lai\n");
        printf("*  5. Thoat.\n");
        printf("*--------------------------------------------------*\n");
        printf("\n\n Nhap lua chon cua ban:   ");
        fflush(stdin);
        scanf("%c", &n);
        fflush(stdin);
        switch (n)
        {
        case '1':
            printf("Vao chuc nang 1:\n");
            ThongTinCuaHang(Arr);
            break;
        case '2':
            printf("Vao chuc nang 2:\n");
            XoaMonHang(Arr);
            PrintList(Arr);
            break;
        case '3':
            printf("Vao chuc nang 3:\n");
            ThemCuaHang (Arr);
            PrintList(Arr);
            break;
        case '4':
            printf("Vao chuc nang 4:\n");
            break;
        case '5':
            exit(0);
            break;
        default:
            printf("Khong co chuc nang nay!\n");
            break;
        }
    }
}

int main()
{
    Node Arr[10];
    Menu (Arr);
}